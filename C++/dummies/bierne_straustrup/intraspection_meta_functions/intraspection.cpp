#include <type_traits>
#include <iostream>

//
struct Substitution_failure
{
};

template<typename T>
struct Substitution_succeeded : std::true_type
{
};

template<>
struct Substitution_succeeded<Substitution_failure>: std::false_type
{
};

template<typename T>
struct get_f_result
{
private:
    template<typename X>
    static auto check(X const& x) -> decltype(f(x));    // если можем вызвать f(x)

    static Substitution_failure check(...);             // если не можем

public:
    using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_f : Substitution_succeeded<typename get_f_result<T>::type>
{};

template <typename T>
constexpr bool Has_f()
{
    return has_f<T>::value; // value given by typetraits std::false_type or std::true_type
};

//

struct Exist_F
{};

struct Not_exist_F
{};

int f(Exist_F const&)
{
    return 5;
}

template<typename T>
struct std::enable_if<false, T> {};

template<bool B, typename T = void>
using Enable_if = std::enable_if<B, T>::type;

template<typename T>
class X
{
public:
    std::enable_if<Has_f<T>(), int>::type use_f(const T& t)
    {
        return f(t);
    }
};

int main()
{

    std::cout << Substitution_succeeded<int>{} << std::endl;

    Exist_F ef;
    Not_exist_F nef;

    X<Exist_F> x_ef;
    // X<Not_exist_F> x_nef;    // not substitutable because have't f(Not_Exist_F const&) signature

    std::cout << x_ef.use_f(ef) << std::endl;

    return 0;
};
