#include "calc_integral.hpp"

#include <iostream>
#include <vector>
#include <utility>

#include <assert.h>


int main(int argc, char** argv) {

    std::vector<std::pair<int, int>> intPoint = {{0, 2}, {2, 4}, {4, 5}, {5, 1}};
    auto intSquare  = integralLeibniz<std::vector<std::pair<int, int>>>(intPoint);
    assert(intSquare == 18);

    std::vector<std::pair<double, double>> doublePoint = {{0, 2}, {2, 4}, {4, 5}, {5, 1}};
    auto doubleSquare  = integralLeibniz<std::vector<std::pair<int, int>>>(intPoint);
    assert((doubleSquare  - 18) <= 0.00001);

    std::cout <<  intSquare << std::endl;

    return 0;
}
