#include <iostream>
#include <fstream>
#include <iostream>

constexpr int BUFF_SIZE = 10;

class Grandparent {
public:
    virtual void grandparent_foo() {}
    int grandparent_data;
};

class Parent1 : virtual public Grandparent {
public:
    virtual void parent1_foo() {}
    int parent1_data;
};

class Parent2 : virtual public Grandparent {
public:
    virtual void parent2_foo() {}
    int parent2_data;
};

class Child : public Parent1, public Parent2 {
public:
    virtual void child_foo() {}
    int child_data;
};

int main(int argc, char** argv)
{
    const char* file_name = "data_layout_with_virtual_inheritance_and_methods_bin_representation";
    Child child;

    std::ofstream f1(file_name, std::ios::binary | std::ios::out);
    f1.write((char*)&child, sizeof(Child));

    auto real_size = sizeof(child);
    auto usefull_size = sizeof(child.parent1_data) + sizeof(child.parent2_data) + sizeof(child.grandparent_data);
    std::cout << (real_size == usefull_size) << std::endl;
    std::cout << "Inherited alligned size: " << real_size << std::endl;
    std::cout << "Inherited real usefull data size: " << usefull_size << std::endl;

    return 0;
}
