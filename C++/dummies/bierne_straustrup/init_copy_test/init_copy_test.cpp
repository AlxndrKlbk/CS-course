#include "virtual_inheritance.cpp"
#include "base_with_pure_virtual_implemented.cpp"
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
    B(const B& rhs) { cout << "b"; }
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
    E& operator=(const E& rhs) {cout << "'E::oper='"; return *this; }
};


// non virtual impl
class B_non_virtal: public A
{
public:
    B_non_virtal() { cout << "B_non_virtal"; }
    B_non_virtal(const B_non_virtal& rhs) : A(rhs) { cout << "b_non_virtal"; }
};

class S: public B_non_virtal
{
public:
    S() { cout << "S"; }
    S(const S& rhs) : B_non_virtal(rhs) { cout << "s"; }
    S& operator=(const S& rhs) {cout << "'S::oper='"; return *this; }
};
// end no virtual

template<typename T>
void t_usage()
{
    T t1;
    cout << std::endl;

    T t2 = t1;
    cout << std::endl;

    t2 = t1;
    cout << std::endl;
}

int main()
{
    t_usage<D>();
    t_usage<E>();
    t_usage<S>();

    test();
    test_base_with_pure_virtual_implementation();

    return 0;
}

// d1 init: A B C D
// d2 init: A B C d
// e1 init: A B C E
// e2 init: A b c e
