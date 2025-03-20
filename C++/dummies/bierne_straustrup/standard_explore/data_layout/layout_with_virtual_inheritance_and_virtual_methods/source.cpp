#include <cstring>
#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 10;

struct Base {

    Base() = default;

    Base(const char* name, int age)
        : mAge(age)
    {
        strncpy(mName, name, BUFF_SIZE);
    }

    virtual void DoSomething()
    {
        std::cout << "Base::DoSomething" << std::endl;
    }

    int mAge;
    char mName[BUFF_SIZE]{0};
};

struct Inherited : public Base
{
    Inherited(const char* name, int age) : Base(name, age)
    {
    }

    virtual void DoSomething() override
    {
        std::cout << "Inherited::DoSomething" << std::endl;
    }
};

struct InheritedVirtual : virtual public Inherited
{
    InheritedVirtual(const char* name, int age) : Inherited(name, age)
    {
    }

    virtual void DoSomething() override
    {
        std::cout << "InheritedVirtual::DoSomething" << std::endl;
    }
};


int main(int argc, char** argv)
{
    const char* file_name = "data_layout_with_virtual_inheritance_and_methods_bin_representation";
    Inherited inherited_non_virtual("Johny", 20);

    std::ofstream f1(file_name, std::ios::binary | std::ios::out);
    f1.write((char*)&inherited_non_virtual, sizeof(Inherited));

    auto real_size = sizeof(inherited_non_virtual);
    auto usefull_size = sizeof(inherited_non_virtual.mAge) + sizeof(inherited_non_virtual.mName);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Inherited alligned size: " << real_size << std::endl;
    std::cout << "Inherited real usefull data size: " << usefull_size << std::endl;

    char padding[BUFF_SIZE](0);
    f1.write(padding, sizeof(padding));

    InheritedVirtual inherited_virtual("Johny", 20);
    f1.write((char*)&inherited_virtual, sizeof(InheritedVirtual));
    f1.close();

    real_size = sizeof(inherited_virtual);
    usefull_size = sizeof(inherited_virtual.mAge) + sizeof(inherited_virtual.mName);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "InheritedVirtual alligned size: " << real_size << std::endl;
    std::cout << "InheritedVirtual real usefull data size: " << usefull_size << std::endl;

    return 0;
}
