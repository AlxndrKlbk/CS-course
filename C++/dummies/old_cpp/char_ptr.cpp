#include <iostream>
#include <vector>

using std::cout;


void usage_char_massive();
void usage_char_ptr();
void test_vec();

int main()
{
    usage_char_massive();
    usage_char_ptr();
    test_vec();
    return 0;
}

void usage_char_massive()
{
    cout << "-------" << std::endl << __PRETTY_FUNCTION__ << std::endl;
    char char_massive[] = "char_ptr text";  // 13 + 1 null-rerminate simbol
    cout << char_massive << std::endl;

    auto size = sizeof(char_massive);
    cout << size<< " bytes to contain text"<< std::endl;
    cout << "it's contain " << size / sizeof(char) << std::endl;

    char_massive[10] = 'A';
    cout << char_massive << std::endl;

    size = sizeof(char_massive);
    cout << size<< " bytes to contain text"<< std::endl;
    cout << "it's contain " << size / sizeof(char) << std::endl;
}

void usage_char_ptr()
{
    cout << "-------" << std::endl << __PRETTY_FUNCTION__ << std::endl;
    const char text[] = "char_ptr text";

    // string literals defined with "char *" allocate at read-only memory
    // and change it by pointer causes sigenv
    // char* char_ptr = "char_ptr text";  // 13 + 1 null-rerminate simbol
    char* char_ptr = const_cast<char *>(text);
    cout << char_ptr << std::endl;

    char* non_const_ptr = const_cast<char*>(char_ptr);

    auto size = sizeof(non_const_ptr);
    cout << size<< " bytes to contain text"<< std::endl;
    cout << "it's contain " << size / sizeof(char) << std::endl;

    auto m = non_const_ptr + 10;
    *m = '!';

    cout << "mutable ptr:" << non_const_ptr << std::endl;
    cout << "not_mutable ptr:" << char_ptr << std::endl;

    size = sizeof(char_ptr);
    cout << size<< " bytes to contain text"<< std::endl;
    cout << "it's contain " << size / sizeof(char) << std::endl;
}

class A {
    int i;
public:
    A(int a): i(a) {}

    A() = default;
};

void test_vec()
{
    std::vector<A> vec;
    vec.resize(10); // required default constructor or user-defined with param
}
