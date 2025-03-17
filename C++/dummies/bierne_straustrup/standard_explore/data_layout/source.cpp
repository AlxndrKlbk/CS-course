#include <cstring>
#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 256;

struct MyData {

    MyData() = default;

    MyData(const char* name, int age)
        : mAge(age)
    {
        strncpy(mName, name, BUFF_SIZE);
    }

    int mAge;
    char mName[BUFF_SIZE]{0};
};

struct DataWithAllignTest {
    char mA;
    int mAge;
    char mB;
};

struct DataWithoutAllignTest {
    char mA;
    int mAge;
    char mB;
} __attribute__((packed));

struct DataWithoutOptimalOrder {
    char mA;
    char mB;
    int mAge;
};

int main(int argc, char** argv)
{
    const char* file_name_1 = "data_layout_bin_representation";
    MyData data("Johny", 20);

    std::ofstream f1(file_name_1, std::ios::binary | std::ios::out);
    f1.write((char*)&data, sizeof(MyData));
    f1.close();

    MyData data_readed;
    std::ifstream f2(file_name_1, std::ios::binary | std::ios::in);
    f2.read((char*)&data_readed, sizeof(data_readed));
    f2.close();

    std::cout << (data_readed.mAge == data.mAge) << std::endl;
    std::cout << (strcmp(data_readed.mName, data.mName) == 0) << std::endl;

    const char* file_name_2 = "data_layout_bin_representation_2";

    DataWithAllignTest allign_data('a', 20, 'b');
    std::ofstream f3(file_name_2, std::ios::binary | std::ios::out);
    f3.write((char*)&allign_data, sizeof(DataWithAllignTest));

    auto real_size = sizeof(allign_data);
    auto usefull_size = sizeof(allign_data.mA) + sizeof(allign_data.mAge) + sizeof(allign_data.mB);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Alligned size: " << real_size << std::endl;
    std::cout << "Real usefull data size: " << usefull_size << std::endl;

    char padding_buff[16]{0};
    f3.write(padding_buff, sizeof(padding_buff));

    DataWithoutAllignTest no_allign_data('a', 20, 'b');
    f3.write((char*)&allign_data, sizeof(DataWithAllignTest));

    real_size = sizeof(no_allign_data);
    usefull_size = sizeof(no_allign_data.mA) + sizeof(no_allign_data.mAge) + sizeof(no_allign_data.mB);
    std::cout << "No allign struct" << std::endl;
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Alligned size: " << real_size << std::endl;
    std::cout << "Real usefull data size: " << usefull_size << std::endl;

    f3.write(padding_buff, sizeof(padding_buff));

    DataWithoutOptimalOrder mData('a', 'b', 20);
    f3.write((char*)&mData, sizeof(DataWithoutOptimalOrder));
    f3.close();
    real_size = sizeof(mData);
    usefull_size = sizeof(mData.mA) + sizeof(mData.mAge) + sizeof(mData.mB);
    std::cout << "Optimal order struct" << std::endl;
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Alligned size: " << real_size << std::endl;
    std::cout << "Real usefull data size: " << usefull_size << std::endl;

    return 0;
}
