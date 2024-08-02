#include <iostream>
#include <memory>

class BaseWithoutVirtual {
public:
    BaseWithoutVirtual() { print(); }

    ~BaseWithoutVirtual() { print(); }

    void print() { std::cout << " Base print"<< std::endl; }    //1

    void basePrint() { print(); }
};

class Base1 {
public:
    Base1() { print(); }

    virtual ~Base1() { std::cout << "destruction: "; print(); }

    // void print() { std::cout << " Base print"<< std::endl; }    //1

    virtual void print()  { std::cout << " Base print"<< std::endl; } //2

    void basePrint() { print(); }
};

class Derived1 : public Base1 {
public:
    Derived1() { print(); }

    ~Derived1() { std::cout << "destruction: " ; print(); }

    // virtual void print() { std::cout << " Derived print" << std::endl; }    //1

    virtual void print() override { std::cout << " Derived print" << std::endl; }    //2

    // virtual void print() override { throw 1; std::cout << " Derived print" << std::endl; }    //3

};

static void test() {
    std::cout << std::endl << "Test Derived and Base with virtual methods" << std::endl;

    Base1* ptr = new Derived1;
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
    std::cout << "Base: " << sizeof(Base1) << std::endl;
    std::cout << "Derived: " << sizeof(Derived1) << std::endl;
}
