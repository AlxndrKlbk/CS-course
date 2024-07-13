#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A"; }
    A(const A &) { cout << "a"; }
};


class B: public virtual A
{
public:
    B() { cout << "B"; }
    B(const B &) { cout << "b"; }
};


class C: public virtual A
{
public:
    C() { cout << "C"; }
    C(const C &) { cout << "c"; }
};


class D: B, C
{
public:
    D() { cout << "D"; }
    D(const D &) { cout << "d"; }
};


int main()
{
    D d1;
    cout << std::endl;
    D d2 = d1;

    return 0;
}

// d1 init: A B C D
// d2 init: A B C D
