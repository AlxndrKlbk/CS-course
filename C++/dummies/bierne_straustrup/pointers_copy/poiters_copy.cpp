#include <iostream>

// shallow copy constructor
class A_bad {
public:
    int* a;
    A_bad() : a(new int[2]) {}
    ~A_bad() { delete[] a; } // double free if give A_bad by value
};

// deep copy with massive and keeping array size, if need use integrated array instead std::vector or std::array
class A {
public:
    uint size_a = 2;
    int* a;

    A() : a(new int[size_a]) {}

    A(const A& other) { // copy constructor
        a = new int[other.size_a];
        for (auto i = 0 ; i < size_a; i++) {
            a[i] = other.a[i];
        }
    }

    ~A() { delete[] a; }
};

void test(A a)
{
    std::cout << a.a[0] << std::endl;
    std::cout << a.a[1] << std::endl;
}

int main()
{
    A a;
    a.a[0] = 1;
    a.a[1] = 2;
    test(a);

    return 0;
}
