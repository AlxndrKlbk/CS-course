#include "func_parity_check.hpp"

#include <assert.h>

namespace {

bool parallel(double a1, double a2, double b1, double b2)
{
    if ((a1 / a2) == (b1 / b2))
    {
        return true;
    }
    return false;
}

void intersect(double a1, double a2, double b1, double b2, double c1, double c2, double& x, double& y)
{
    double det = a1 * b2 - a2 * b1;
    x = (b1 * c2 - b2 * c1) / det;
    y = (a2 * c1 - a1 * c2) / det;
}

}

int main(int argc, char** argv) {

    if (argc != 3) {
        return 1;
    }

    // first file
    auto intPoints = load_from_file<int>(argv[1]);
    if (!intPoints) {
        return 1;
    }

    auto is_parity = check_func_parity(std::move(intPoints.value()));
    std::cout << is_parity << std::endl;


    // second file
    auto longPoints = load_from_file<long>(argv[2]);
    if (!longPoints) {
        return 1;
    }

    is_parity = check_func_parity(std::move(longPoints.value()));
    std::cout << is_parity << std::endl;

    return 0;
}
