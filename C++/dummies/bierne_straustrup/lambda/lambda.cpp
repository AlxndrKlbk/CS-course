#include <iostream>


class FuncObject
{
public:
    auto operator()() const
    {
        std::cout << "function object with behavior like lambda" << std::endl;
    }
};

int add_one(int i)
{
    return i + 1;
}

int main()
{
    const char* text = "some_text";

    FuncObject like_lambda;
    like_lambda();

    auto regular_lambda = []() { std::cout << "lambda" << std::endl; };
    // or like that
    // auto regular_lambda {[]() { std::cout << "lambda" << std::endl; }};

    regular_lambda();

    auto capture_lambda = [text](){ std::cout << text << std::endl; };
    capture_lambda();

    // C-style function pointer
    int (*add_one_ptr)(int) = add_one;

    std::cout << add_one_ptr(1) << std::endl;

    return 0;
}
