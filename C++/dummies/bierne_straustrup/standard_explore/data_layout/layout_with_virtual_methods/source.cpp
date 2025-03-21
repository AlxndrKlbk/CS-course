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

    virtual void DoMethingNotOverride() {}

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

int main(int argc, char** argv)
{
    const char* file_name = "data_layout_with_virtual_methods_bin_representation";
    Base base("Johny", 20);

    std::ofstream f1(file_name, std::ios::binary | std::ios::out);
    f1.write((char*)&base, sizeof(Base));

    auto real_size = sizeof(base);
    auto usefull_size = sizeof(base.mAge) + sizeof(base.mName);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Base alligned size: " << real_size << std::endl;
    std::cout << "Base real usefull data size: " << usefull_size << std::endl;

    char padding[BUFF_SIZE](0);
    f1.write(padding, sizeof(padding));

    Inherited inherited("Johny", 20);
    f1.write((char*)&inherited, sizeof(Inherited));
    f1.close();

    real_size = sizeof(inherited);
    usefull_size = sizeof(inherited.mAge) + sizeof(inherited.mName);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Inherited alligned size: " << real_size << std::endl;
    std::cout << "Inherited real usefull data size: " << usefull_size << std::endl;

    return 0;
}
