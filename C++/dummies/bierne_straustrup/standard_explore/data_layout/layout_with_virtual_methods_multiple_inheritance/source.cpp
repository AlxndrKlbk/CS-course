#include <cstring>
#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 10;

class Mother {
public:
    virtual void MotherMethod() {}
    int mother_data;
};

class Father {
public:
    virtual void FatherMethod() {}
    int father_data;
};

class Child : public Mother, public Father {
public:
    virtual void ChildMethod() {}
    int child_data;
};

int main(int argc, char** argv)
{
    const char* file_name = "data_layout_with_virtual_methods_bin_representation";
    Child child;

    std::ofstream f1(file_name, std::ios::binary | std::ios::out);
    f1.write((char*)&child, sizeof(child));

    auto real_size = sizeof(child);
    auto usefull_size = sizeof(child.child_data) + sizeof(child.father_data) + sizeof(child.mother_data);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Base alligned size: " << real_size << std::endl;
    std::cout << "Base real usefull data size: " << usefull_size << std::endl;

    return 0;
}
