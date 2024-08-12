#include <unistd.h>
#include <iostream>

// how much 'Hello!' would be here?

int main(int argc, char **argv) {
    fork();
    fork();
    fork();
    fork();
    std::cout << "Hello!\n";
}
