#include <iostream>

namespace {

struct Base
{
    virtual void f(int x) = 0;

    Base () {
        // f(1); // not allowed to call Base::f
    }
};

void Base::f(int x) {
    std::cout << x;
}

struct Derived: Base {

    Derived() {
        Base::f(1); // allowed
        f(1);
    }

    void f(int x) override {
        std::cout << -x;
    }
};

}

static void test_base_with_pure_virtual_implementation() {
    std::cout << std::endl << "test_base_with_pure_virtual_implementation" << std::endl;
    Derived d;
}
