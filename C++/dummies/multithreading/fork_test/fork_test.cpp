#include <unistd.h>
#include <iostream>

int main(int argc, char **argv) {
    fork();
    fork();
    fork();
    fork();
    std::cout << "Hello!\n";
}
