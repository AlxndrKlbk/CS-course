#include <iostream>
#include <memory>

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

    virtual ~Base() { std::cout << "destruction: "; print(); }

    // void print() { std::cout << " Base print"<< std::endl; }    //1

    virtual void print()  { std::cout << " Base print"<< std::endl; } //2

    void basePrint() { print(); }
};

class Derived : public Base {
public:
    Derived() { print(); }

    ~Derived() { std::cout << "destruction: " ; print(); }

    // virtual void print() { std::cout << " Derived print" << std::endl; }    //1

    virtual void print() override { std::cout << " Derived print" << std::endl; }    //2

    // virtual void print() override { throw 1; std::cout << " Derived print" << std::endl; }    //3

};

static void test() {
    std::cout << std::endl << "Test Derived and Base with virtual methods" << std::endl;

    Base* ptr = new Derived;
    ptr->basePrint();
    delete ptr;

    // try {
    //     auto ptr = std::make_shared<Derived>();

    //     ptr->basePrint();

    //     // delete ptr;
    // }
    // catch   (...) {
    // }    // 3
    std::cout << "BaseWithoutVirtual: " << sizeof(BaseWithoutVirtual) << std::endl;
    std::cout << "Base: " << sizeof(Base) << std::endl;
    std::cout << "Derived: " << sizeof(Derived) << std::endl;
}
