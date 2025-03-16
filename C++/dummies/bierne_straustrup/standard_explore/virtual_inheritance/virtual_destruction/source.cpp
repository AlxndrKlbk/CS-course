#include <iostream>

class Base {
public:
    virtual void doSomething() = 0;
    // {
    //     std::cout << "Base dp something" << std::endl;
    // }

    virtual ~Base()
    {
        // Pure virtual method call error, "CRASH"
        // ~Inherited() -> remove pointer to vtable of Inherited -> ~Base() -> call doSomething() -> \
        // -> Not found implementation for Inherited->doSomething() -> "Error pure virual method call"
        doSomething();
    }

// private:
//     void doSomething()
//     {
//         std::cout << "Not virtual" << std::endl;
//     }
};

class Inherited : public Base
{
    virtual void doSomething() override
    {
        std::cout << "Inherited do something" << std::endl;
    }

};

int main() {
    Base*  pBase =  new Inherited();
    delete pBase;
    return 0;
}
