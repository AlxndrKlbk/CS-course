#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A"; }
    A(const A&) { cout << "a"; }
};


class B: public virtual A
{
public:
    B() { cout << "B"; }
    B(const B&) { cout << "b"; }
};


class C: public virtual A
{
public:
    C() { cout << "C"; }
    C(const C&) { cout << "c"; }
};


class D: B, C
{
public:
    D() { cout << "D"; }
    D(const D&) { cout << "d"; }
};

class E: B, C
{
public:
    E() { cout << "E"; }
    E(const E& rhs) : B(rhs), C(rhs) { cout << "e"; }
};

template<typename T>
void t_usage()
{
    T t1;
    cout << std::endl;

    T t2 = t1;
    cout << std::endl;
}

int main()
{
    t_usage<D>();
    t_usage<E>();
    return 0;
}

// d1 init: A B C D
// d2 init: A B C d
// e1 init: A B C E
// e2 init: A b c e
