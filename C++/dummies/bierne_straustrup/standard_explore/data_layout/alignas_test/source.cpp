#include <cstring>
#include <iostream>
#include <fstream>

static_assert(true); // just to avoid clangd warning for pragma https://github.com/clangd/clangd/issues/1167.
#pragma pack(push, 1)
struct PackedStruct
{
    short x;
    int y;
    short z;
};
#pragma pack(pop)

struct AlignasStruct
{
    alignas(16) short x; // выравнивание по 16, к 2 байтам будет добавлено 14 мусор адля выравнивания              total: 16
    alignas(16) int y;   // выравнивание по 16, т.к. прошлое поле уже выравнено, то займет честные 4 байта int     total: 20
    short z;             // концевое выравнивание, т.к прошлый адрес кратен 2, то к int выравнивания нет, требуется 2, будет добавлено еще 10 байт для выравнивания
                         // следующей стркутуры, итого 32 байта                                                    total: 32
};

int main(int argc, char** argv)
{
    const char* file_name_1 = "alignas_test_bin_representation";

    PackedStruct data(20, 20, 20);

    auto size = sizeof(PackedStruct); //вернёт 8 байт
    std::cout << "pack sizeof :" << size << std::endl;

    std::ofstream f1(file_name_1, std::ios::binary | std::ios::out);
    f1.write((char*)&data, sizeof(PackedStruct));

    char padding[8](0);
    f1.write(padding, sizeof(padding));

    AlignasStruct data2(20, 20, 20);
    size = sizeof(AlignasStruct); //вернёт 32 байта
    std::cout << "alignas sizeof :" << size << std::endl;
    f1.write((char*)&data2, sizeof(AlignasStruct));
    f1.close();

    char c[4] = {0x00, 0x00, 0x00, static_cast<char>(0x80)};
    int ival = *reinterpret_cast<int*>(c);
    float fval = *reinterpret_cast<float*>(c);
    unsigned int uival = *reinterpret_cast<unsigned int*>(c);

    return 0;
}
