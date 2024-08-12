#include <future>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <list>

#include <assert.h>

template <typename IT, typename Func1, typename Func2>
auto foo(IT p, IT q, Func1 f1, Func2 f2) -> decltype(f2(f1(*p), f1(*p)))
{
    auto res = f1(*p);
    while (++p != q)
        res = f2(res, f1(*p));
    return static_cast<decltype(f2(f1(*p), f1(*p)))>(res);
}

template <typename IT, typename Func1, typename Func2>
auto map_reduce(IT p, IT q, Func1 f1, Func2 f2, size_t threads) -> decltype(f2(f1(*p), f1(*p)))
{
    using TypeRes = decltype(f2(f1(*p), f1(*p)));
    int length = std::distance(p, q);

    std::vector<std::future<TypeRes>> vecFut;

    for (int i = 0; i < threads; i++)
    {
        auto p1 = p;
        auto q1 = p;
        std::advance(p1, static_cast<int>(i * length / threads));
        std::advance(q1, static_cast<int>((i + 1) * length / threads));
        std::future<TypeRes> fut = std::async(std::launch::async, foo<IT, Func1, Func2>, p1, q1, f1, f2);
        vecFut.emplace_back(std::move(fut));
    }

    auto res = vecFut[0].get();

    for(int i = 1; i < threads; i++){
        res = f2(res, vecFut[i].get());
    }

    return res;
}

int main(int argc, char** arv) {

    std::list< int > const l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // параллельное суммирование в 3 потока
    auto sum = map_reduce(l1.begin(), l1.end(), []( int i ){ return i; }, std::plus< int >(), 3);

    std::cout << sum << std::endl;
    assert( sum == 55 );

    // проверка наличия чётных чисел в четыре потока
    auto has_even = map_reduce(l1.begin(), l1.end(), []( int i ){ return i % 2 == 0; }, std::logical_or< bool >(), 4);
    std::cout << has_even << std::endl;
    assert( has_even == true );

    std::vector< std::string > const v1 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
    for (std::size_t j = 1; j <= v1.size(); ++j )
    {
        auto ssum = map_reduce(v1.begin(), v1.end(), []( std::string s ){ return s; }, std::plus< std::string >(), j);
        std::cout << ssum << std::endl;
        assert( ssum == "1234567891011" );
    }

    std::list<int> const l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    for (int i = 1; i < 20; ++i)
    {
        auto ssum = map_reduce(l2.begin(), l2.end(), []( int j ){ return j; }, std::plus< int >(), i);
        std::cout << ssum << std::endl;
        assert( ssum == 190 );
    }

    std::vector< std::string > const v2 = {"multithread", "and", "async", "in", "C++", "is", "total"};
    for ( std::size_t i = 1; i <= 8; ++i )
    {
        auto size_sum = map_reduce(v2.begin(), v2.end(), []( std::string s ){ return s.size(); }, std::plus< std::size_t >(), i);
        std::cout << size_sum << std::endl;
        assert(size_sum == 31);
    }

    return 0;
}
