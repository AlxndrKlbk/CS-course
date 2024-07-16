#include <iostream>
#include <type_traits>

template<typename T>
struct std::enable_if<false, T> {};

template<bool B, typename T = void>
using Enable_if = std::enable_if<B, T>::type;

template<typename T>
constexpr bool Is_class()
{
    return std::is_class<T>::value;
}

template<typename T>
class Smart_pointer
{
public:

    Smart_pointer(T* ptr): T_ptr(ptr) {};

    ~Smart_pointer() { delete T_ptr; }

    T& operator*();

    Enable_if<Is_class<T>(), T>* operator->() { return T_ptr; }

private:
    T* T_ptr;
};


class Test_A
{
public:

    explicit Test_A(double val) : d{val} {}

    double d = 4;
};

int main()
{
    auto sa = Smart_pointer<Test_A>(new Test_A{4.0});
    std::cout << sa->d << std::endl;

    // контроль "Концепции" в объявлении шаблона, компилятор стреляет ошибкой на этапе конретизации
    // auto sm = Smart_pointer<double>();
    // std::cout << sm->real();
    return 0;
}
