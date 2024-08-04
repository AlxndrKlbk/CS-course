#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <math.h>

std::string derivative(std::string polynomial);

inline void test_derived(const std::string& input, const std::string& expected) {
    std::string d = derivative(input);
    if (d != expected) {
        std::stringstream msg;
        msg << input << "[" << d << "] != " << expected;
        throw std::logic_error(msg.str());
    }
}

int main(int argc, char** argv) {

    std::string polyStr{argv[1]};

    std::cout << "initial polynom: " << polyStr << std::endl;
    std::cout << "derivateved polynom: " << derivative(polyStr) << std::endl;

    test_derived("x^2+x", "2*x+1");
    test_derived("2*x^100+100*x^2", "200*x^99+200*x");
    test_derived("x^10000+x+1", "10000*x^9999+1");
    test_derived("-x^2-x^3", "-3*x^2-2*x");
    test_derived("x+x+x+x+x+x+x+x+x+x", "10");
    test_derived("x", "1");
    test_derived("5", "0");
    test_derived("10*x-9*x", "1");
    test_derived("x^2+x", "2*x+1");
    test_derived("x+x^2", "2*x+1");
    test_derived("x+x^2+x^3", "3*x^2+2*x+1");
    test_derived("5", "0");
    test_derived("5+9", "0");
    test_derived("-x", "-1");
    test_derived("-1*x", "-1");
    test_derived("1*x", "1");
    test_derived("x", "1");
    test_derived("+x", "1");
    test_derived("2*x^0", "0");
    test_derived("1-x^2", "-2*x");

    return 0;
}

// used to inverse output for over map
class comparator {
public:
    bool operator()(const int& x,const int& y) const
    { return x > y; }
};

std::map<int, int, comparator> polyToMap(std::string const& polynomial) {
    std::map<int, int, comparator> degreeAndCoeff;
    int sign{1}, coef{0}, degree{0};

    enum {ReadCoeff, ReadDegree} readState = ReadCoeff;

    for (auto i = polynomial.cbegin(); i <= polynomial.cend(); i++) {
        const char cursor = *i;
        switch (readState)
        {
        case ReadCoeff:
        {
            if (cursor == '+') {
                sign = 1;
            } else if (cursor == '-') {
                sign = -1;
            } else if (cursor == 'x' || cursor == '^' || cursor == '*') {
                degree = 1;
                if (coef == 0) coef++;
                readState = ReadDegree;
            } else {
                coef = coef * 10 + cursor - '0';
            }
            break;
        }
        case ReadDegree:
        {
            if (cursor == '+' || cursor == '-' || cursor == '\0') {
                degreeAndCoeff[degree] += coef * sign;
                degree = coef = 0;
                if (cursor == '+') {
                    sign = 1;
                } else if (cursor == '-') {
                    sign = -1;
                }
                readState = ReadCoeff;
            } else if (!(cursor == 'x' || cursor == '^' || cursor == ' ')) {
                degree = degree * 10 + cursor - '0';
            } else if (cursor == '^') {
                degree = 0;
            }
            break;
        }
        default:
            break;
        }

    }
    return degreeAndCoeff;
}

std::string derivative(std::string polynomial) {
    auto degreeAndCoeff = polyToMap(polynomial);
    std::string derivative;
    for (auto pair : degreeAndCoeff) {
        if (pair.second > 0) {
            derivative += '+';
        } else {
            derivative += '-';
        }

        if (pair.first != 0 && pair.second != 0) {
            derivative += std::to_string(abs(pair.second * pair.first));
            auto degree = pair.first - 1;
            if (degree == 0) {
                continue;
            } else if (degree == 1) {
                derivative += "*x";
            } else if (degree > 1) {
                derivative += "*x^" + std::to_string(degree);
            }
        }
    }
    if (derivative[0] == '+') {
        derivative.erase(0, 1);
    }
    if (derivative == "") {
        derivative = "0";
    }
    return derivative;
}
