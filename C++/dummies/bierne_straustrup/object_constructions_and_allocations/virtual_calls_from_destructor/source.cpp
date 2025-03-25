#include <iostream>
#include <unistd.h>

class Base
{
public:
    virtual void function1() { std::cout << "Base::function1()\n"; }
    virtual ~Base() { function1(); } // Виртуальный деструктор
};

class BasePureVirtual
{
public:
    virtual void function1() = 0;
    virtual ~BasePureVirtual() { function1(); } // Виртуальный деструктор, pure virtual fnuction call
};

class Derived : public Base
{
public:
    void function1() override { std::cout << "Derived::function1()\n"; }
    ~Derived() override { function1(); } // Деструктор производного класса
};

class DerivedFromPureBase : public BasePureVirtual
{
public:
    void function1() override { std::cout << "Derived::function1()\n"; }
    ~DerivedFromPureBase() override { function1(); } // Деструктор производного класса
};

int main() {
    Base* b = new Derived();
    delete b;
    std::cout << "ок, но деструктор Base вызовет base::function1()" << std::endl;

    BasePureVirtual* bPure = new DerivedFromPureBase();
    delete bPure; // не ок, десруктор Base сделает вызов Pure Virtual Function и случится дамп

    return 0;
}
