#include <thread>
#include <iostream>
#include <string>

void run(std::string threadName) {
    for (int i = 0; i < 10; i++) {
        std::string out = threadName + std::to_string(i) + "\n";
        std::cout << out;
    }
}

/*
 * Illustrate undefind order of thread execustion
 */
int main() {
    std::thread tA(run, "A");
    std::thread tB(run, "\tB");
    tA.join();
    tB.join();
}
