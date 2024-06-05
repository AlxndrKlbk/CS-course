#include "pointers_to_massives.hpp"

#include <string.h>
#include <iostream>

int main(int argc, char** argv)
{
    int v[] = {1, 2, 3, 4};
    // int* p1 = v;
    // int* p2 = &v[0];
    int* p3 = v + 4;

    *p3 = 2;

    for (int i = 0; i < 4; i++) {
        std::cout <<  v[i] << " ";
    }

    std::cout << std::endl << "___" << std::endl;
    for (int* r = v; *r != 0; r++) {
        std::cout << r << std::endl;
    }

    std::cout << std::endl << "___" << std::endl;
    // a[j] = *(&a[0]+j) == *(a+j) == (j+a) == j[a]
    std::cout << v[1] << std::endl;
    std::cout << *(&v[0] + 1) << std::endl;
    std::cout << *(v+1) << std::endl;
    std::cout << 1[v] << std::endl;

    implicitConversion();
    testByteDiff();
    return 0;
}

// extern "C" int strlen(const char*); // from #include <string.h>

void implicitConversion()
{
    std::cout << std::endl << "implicitConversion" << std::endl;
    char v[] = "Annemarie";
    char* p = v;
    std::cout << strlen(p) << std::endl;
    std::cout << strlen(v) << std::endl;

    // possible convert char[] to char*, but not vice versa
    // v = p;
}

void testByteDiff()
{
    std::cout << std::endl << "testByteDiff" << std::endl;

    int vi[10];
    short vs[10];
    std::cout << vi << ' ' << &vi[1] << ' ' << &vi[1] - &vi[0] << ' ' << byte_diff(&vi[0], &vi[1]) << '\n';
    std::cout << vs << ' ' << &vs[1] << ' ' << &vs[1] - &vs[0] << ' ' << byte_diff(&vs[0], &vs[1]) << '\n';
}
