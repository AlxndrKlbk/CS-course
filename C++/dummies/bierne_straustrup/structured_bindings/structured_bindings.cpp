#include <tuple>
#include <iostream>


int main()
{
    std::tuple<int, float> m_tuple(1, 2.f);
    auto& [firt_m, second_m] = m_tuple;

    auto print_type = [](auto data) {
        std::cout << data << " " << typeid(data).name() << std::endl;
    };

    print_type(firt_m);
    print_type(second_m);

    // array bindings
    int a[2] = {1, 2};
    auto [x, y] = a;    // copies into x, y
    std::cout << x << " " << y << std::endl;

    auto& [xr, yr] = a; // reference to values in a

    return 0;
}
