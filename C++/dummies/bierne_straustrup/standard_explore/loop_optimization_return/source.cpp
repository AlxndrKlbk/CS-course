#include <iostream>

int foo4();


int main(int argc, char** argv)
{
    std::cout << foo4() << '\n'; // loop
}

// no endless loop because code without subeffects and compiler
// optemize body to return 1 (gained in C++2)
int foo4() {
    const int MAX = 1000;
    int a = 1, b = 1, c = 1;
    while (true) {
        if (((a * a * a) == ((b * b * b) + (c * c * c))))
            // недостижимый код, так как теорема Ферма утверждает, что (a * a * a) != (b * b * b) + (c * c * c)
            return 1;
        a++;
        if (a > MAX) {
            a = 1;
            b++;
        }
        if (b > MAX) {
            b = 1;
            c++;
        }
        if (c > MAX) {
            c = 1;
        }
    }
    return 0;
}
