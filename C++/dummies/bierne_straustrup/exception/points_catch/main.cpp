#include <csetjmp>
#include <iostream>
#include <csignal>
#include <thread>
#include <stdexcept>

sigjmp_buf jump_buffer;

double divide(int a, int b)
{
    if(b > a)
    {
        throw "The second number is greater than the first one";
    }

    if (sigsetjmp(jump_buffer, 1) != 0) {
        sigsetjmp(jump_buffer, 0);
        throw std::runtime_error("looks like we come here again after signal handling");
    }

    int res = a/ b;

    return res;
}

void test(int a, int b)
{
    try
    {
        double result {divide(a, b)};
        std::cout << result << std::endl;
    }
    catch (int code)
    {
        std::cout << "Error code: " << code << std::endl;
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
    }
    catch(...)
    {
        std::cout << "Devision by zero" << std::endl;
        // rethrow unexpected error
    }
}

/**
 * @brief sigfpe_handler - only for SIGFPE
 * @param signum
 */
void sigfpe_handler(int signum) {
    std::cout << "Signal " << signum << " received\n";
    siglongjmp(jump_buffer, 1);
}

int main()
{
    std::signal(SIGFPE, sigfpe_handler);

    auto thread = std::thread(test, 100, 20);      // 5
    thread.join();

    thread = std::thread(test,100, 0);       // Error code: devision on zero in thread
    thread.join();

    std::cout << "no fail after devision by zero" << std::endl;
    return 0;
}
