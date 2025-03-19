#include <cstring>
#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 256;

struct foo3 {
    char *p; /* 8 байт */
    char c; /* 1 байт */
};

void no_array_layout()
{
    const char* file_name = "no_array_layout";
    struct foo3 singleton(const_cast<char*>(file_name), 'a');

    std::ofstream file(file_name, std::ios::binary | std::ios::out);
    file.write(reinterpret_cast<char*>(&singleton), sizeof(foo3));
    file.close();

    std::cout << "no array layout" << std::endl;
    std::cout << sizeof(singleton) << std::endl;
}

void with_array_layou()
{
    const char* file_name = "with_array_layout";
    struct foo3 singleton(const_cast<char*>(file_name), 'a');
    struct foo3 quad[4];

    std::ofstream file(file_name, std::ios::binary | std::ios::out);
    file.write(reinterpret_cast<char*>(&singleton), sizeof(foo3));
    file.close();

    std::cout << "with array layout" << std::endl;
    std::cout << sizeof(singleton) << std::endl;
}

int main(int argc, char** argv)
{
    no_array_layout();
    with_array_layou();
    return 0;
}
