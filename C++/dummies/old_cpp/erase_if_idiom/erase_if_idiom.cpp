#include <algorithm>

#include <vector>
#include <iostream>


namespace {

constexpr int BORDER_VALUE_INDEX = 1;
constexpr int VALUES_START_INDEX = 2;

template<typename T>
void vectorPrint(T const& toPrint)
{
    const auto placeholder = "; ";
    for (const auto &i : toPrint)
        std::cout << i << placeholder;
}

}

int main(int argc, char** argv)
{
    char* inputChar = nullptr;

    double filterValue = atof(argv[BORDER_VALUE_INDEX]);

    std::vector<double> buff;
    for (int i = VALUES_START_INDEX; i < argc; i++)
    {
        inputChar = argv[i];
        buff.emplace_back(atof(inputChar));
    }

    std::cout << "before filtering values less then " << filterValue << std::endl;
    vectorPrint(buff);

    std::cout << "after filtering" << std::endl;
    buff.erase(std::remove_if(buff.begin(), buff.end(), [&](const double& val) {
                return val > filterValue == 0;
               }), buff.end());

    std::cout << "after filtering" << std::endl;
    vectorPrint(buff);

    std::cout << std::endl;
    return 0;
}
