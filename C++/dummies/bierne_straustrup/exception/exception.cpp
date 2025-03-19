#include <iostream>

double divide(int a, int b)
{
    if(!b)  // если b == 0
    {
        throw 0;
    }
    if(b > a)
    {
        throw "The second number is greater than the first one";
    }
    return a / b;
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
        std::cout << "Unexpected error" << std::endl;
        // rethrow unexpected error
        throw;
    }
}

int main()
{
    test(100, 20);      // 5
    test(100, 0);       // Error code: 0
    test(100, 1000);    // The second number is greater than the first one
}
