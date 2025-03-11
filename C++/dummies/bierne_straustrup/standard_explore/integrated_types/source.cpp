#include <iostream>
#include <type_traits>
#include <limits>
#include <optional>

void func_begin_print(std::string const& msg)
{
    std::cout << "----------" << std::endl << msg << std::endl << "----------" << std::endl;
}

template<typename Type>
void foo() {
    static size_t i = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << i++ << std::endl;
}

bool foo1(int a) {
    return a < 0;
}

int foo4();

struct A {
    A() = default;
    A(int _a) :a(_a){}

    int a = -1;
};

struct B : virtual A {
    B(int _a) :A(_a) {}
};

struct C : B, virtual A {
    C() : B(100) {}
};

struct D {
    D() = default;
    D(const D&) { std::cout << "D(const D&)" << '\n'; }
    D(D&&) noexcept { std::cout << "D(D&&)" << '\n'; }

    std::string mMsg = "to cout";
};

D foo2() {
    return D();
}

std::optional<D> foo3() {
    auto d = D();
    return d;
}

void test_template_behavior()
{
    func_begin_print(__PRETTY_FUNCTION__);
    foo<const unsigned int>(); // 0
    foo<unsigned int>(); // 1

    foo<size_t>(); // 0 - на ultra 185H по Linux компилятор делает site_t как тайпдеф для unsigned long
    foo<unsigned long int>(); // 1 - т.е. тип что и site_t

    foo<const size_t>(); // 0 - const не отбрасывается

    foo<unsigned long long>();
}

void test_internal_types_comparison()
{
    func_begin_print(__PRETTY_FUNCTION__);
    std::cout << "signed and unsigned comparison" << std::endl;
    std::cout << (-1 < 0u) << '\n'; // 1

    std::cout << "signed long long and unsigned long comparison" << std::endl;
    std::cout << (-1ll < 0ul) << '\n'; // 0
    std::cout << foo1(std::numeric_limits<unsigned int>::max()) << '\n'; // 0
}

void test_char_sign_implementation()
{
    func_begin_print(__PRETTY_FUNCTION__);
    std::cout << std::is_signed_v<char> << '\n'; // 1
    std::cout << std::is_same_v<char, unsigned char> << '\n'; // 0
    std::cout << std::is_same_v<char, signed char> << '\n'; // 0
}

void test_class_construction_with_wierd_inheritance()
{
    func_begin_print(__PRETTY_FUNCTION__);
    C c;
    std::cout << c.a << '\n';
}

void test_with_reference_cast()
{
    func_begin_print(__PRETTY_FUNCTION__);
    const int a = 10;
    std::cout << a << std::endl;
    const int& a_ref = a;
    // a_ref = 2; //cannot assign
    int* a_ptr = const_cast<int *>(&a_ref);
    *a_ptr = 9;
    std::cout << a_ref << std::endl;
    std::cout << a << std::endl;
}

void test_c_style_string_allocations()
{
    func_begin_print(__PRETTY_FUNCTION__);
    const char* txt1 = "qwerty";
    const char* txt2 = "rty";
    std::cout << (txt2 == txt1 + 3) << '\n';
    std::cout << txt1 << std::endl;

    std::cout << "pointers address" << std::endl;
    std::cout << &txt1 << std::endl;
    std::cout << &txt2 << std::endl;

    std::cout << "addresses of pointed data" << std::endl;
    std::cout << reinterpret_cast<void*>(const_cast<char*>(txt1)) << std::endl;
    std::cout << reinterpret_cast<void*>(const_cast<char*>(txt2)) << std::endl;
}

void test_RVO()
{
    func_begin_print(__PRETTY_FUNCTION__);

    auto a = foo2(); // -
    // RVO and no copy or move constructors calls
    std::cout << a.mMsg << std::endl;

    auto b = foo3(); // &
    std::cout << b->mMsg << std::endl;
}

int main() {
    test_template_behavior();
    test_internal_types_comparison();
    test_class_construction_with_wierd_inheritance();
    test_char_sign_implementation();
    test_with_reference_cast();
    test_c_style_string_allocations();
    test_RVO();
}


