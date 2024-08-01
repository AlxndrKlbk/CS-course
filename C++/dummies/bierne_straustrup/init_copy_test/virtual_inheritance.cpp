#include <iostream>

class BaseWithoutVirtual {
public:
    BaseWithoutVirtual() { print(); }

    ~BaseWithoutVirtual() { print(); }

    void print() { std::cout << " Base print"<< std::endl; }    //1

    void basePrint() { print(); }
};

class Base {
public:
    Base() { print(); }

    virtual ~Base() { print(); }

    // void print() { std::cout << " Base print"<< std::endl; }    //1

    virtual void print() { std::cout << " Base print"<< std::endl; } //2

    void basePrint() { print(); }
};

class Derived : public Base {
public:
    Derived() { print(); }

    ~Derived() { print(); }

    // virtual void print() { std::cout << " Derived print" << std::endl; }    //1

    virtual void print() override { std::cout << " Derived print" << std::endl; }    //2
};

static void test() {
    std::cout << "Test Derived and Base with virtual methods" << std::endl;
    Base * ptr = new Derived;

    ptr->basePrint();

    delete ptr;

    std::cout << "BaseWithoutVirtual: " << sizeof(BaseWithoutVirtual) << std::endl;
    std::cout << "Base: " << sizeof(Base) << std::endl;
    std::cout << "Derived: " << sizeof(Derived) << std::endl;
}
