#include <iostream>

class A1
{
public:
    virtual ~A1() = default;

protected:
    virtual void DoSomething() = 0;
};

class A2 : public A1
{
public:
    A2() {
        DoSomething(); // вызов через A2::DoSomething а не A2.vptr->DoSomething()
    }

protected:
    virtual void DoSomething() override
    {
        std::cout << "A2" << std::endl;
    }
};

class A3 : public A2
{
public:
    A3() {
        DoSomething();
    }
protected:
    virtual void DoSomething() override
    {
        std::cout << "A3" << std::endl; // вызов через A3::DoSomething а не A3.vptr->DoSomething()
    }
};

class A4 : protected A2
{
public:
    A4() {
        DoSomething();
    }
};


int main() {
    std::cout << "A4!" << std::endl;
    A4 a4{};

    std::cout << "A3!" << std::endl;
    A3 a3{};

    std::cout << "A2!" << std::endl;
    A2 a2{};

    return 0;
}
