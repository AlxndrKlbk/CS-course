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
    std::cout << std::endl;
}

}

// first arg - value to filter, second and etc fit the vector
// call like erase_remove_idiom 1 1 23234 23 151 125 12512
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

    // Funny that std::remove and std::remove_if just move elements and return iterator to first "junk item"
    // delete them needed by call "buff.erase(result, buff.end()), othervise vector contain valid but undefined items"

    // std::cout << "vector size: " << buff.size() << std::endl;
    // auto const&& val = std::remove_if(buff.begin(), buff.end(), [&](const double& val) {
    //                        return val > filterValue == 0;
    //                    });
    // std::cout << "vector size after remove: " << buff.size() << std::endl;

    buff.erase(std::remove_if(buff.begin(), buff.end(), [&](const double& val) {
                return val > filterValue == 0;
               }), buff.end());

    std::cout << "after filtering" << std::endl;
    vectorPrint(buff);

    std::cout << 0x55 << std::endl;
    return 0;
}
