#pragma once

#include <initializer_list>
#include <string>


template<class T>
void f1(std::initializer_list<T>) {};

struct S
{
    int a;
    std::string s;
};

void f2(S) {};

template<class T, int N>
void f3(T (&&r)[N]) {};

void f4(int) {};

void g()
{
    f1({1, 2, 3, 4,});
    f2({1, "MKS"});
    f3({1, 2, 3, 4});
    f4(1);
}

template<class T, int N>
void f(T (&&r)[N]);

void f(S) {};

template<class T>
void f(std::initializer_list<T>) {};

void f(int) {};

void g1()
{
    f({1, 2, 3, 4,});   // initializer_list priority
    f({1, "MKS"});      // f(S)
    f(1);               // f(int)
}
