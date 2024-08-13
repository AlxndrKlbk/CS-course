
#include <iostream>
#include <vector>
#include <utility>

#include <assert.h>

template<typename T>
double calcIntegtral2(T const& points)
{
    double accumSquere = 0;
    for (int i = 1; i < points.size(); i++) {
        auto prev = points[i-1];
        auto cur = points[i];

        auto y1 = cur.second;
        auto y2 = prev.second;

        auto x1 = cur.first;
        auto x2 = prev.first;
        auto high =  x1 - x2;

        accumSquere +=  (y2 + y1) * 0.5 * high;
    }

    return accumSquere;
}

template<typename T>
double calcIntegtral1(T const& points)
{
    double accumSquere = 0;

    auto cur = points.begin();
    cur++;

    auto prev = points.begin();

    while(prev != points.end()) {

        auto y1 = cur->second;
        auto y2 = prev->second;

        auto x1 = cur->first;
        auto x2 = prev->first;
        auto high =  x1 - x2;

        accumSquere +=  (y2 + y1) * 0.5 * high;

        prev = cur;
        cur++;
    }
    return accumSquere;
}

union CharToDouble {
    double d;
    char bytes[sizeof(double)];
};

int main(int argc, char** argv) {

    std::vector<std::pair<int, int>> intPoint = {{0, 2}, {2, 4}, {4, 5}, {5, 1}};
    // auto intSquare  = calcIntegtral2<std::vector<std::pair<int, int>>>(intPoint);
    auto intSquare   = calcIntegtral2(intPoint);

    assert(intSquare == 18);

    std::vector<std::pair<double, double>> doublePoint = {{0, 2}, {2, 4}, {4, 5}, {5, 1}};
    // auto intSquare  = calcIntegtral1<std::vector<std::pair<int, int>>>(intPoint);
    auto doubleSquare   = calcIntegtral2(intPoint);
    assert((doubleSquare  - 18) <= 0.00001);

    std::cout <<  intSquare << std::endl;

    return 0;
}
