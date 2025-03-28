#include <algorithm>
#include <string>
#include <iostream>

int main() {
    std::string mainString = "some specific string with extera strings!";
    std::string subString = "string";

    auto it = mainString.begin();
    while (it != mainString.end()) {
        it = std::search(it, mainString.end(), subString.begin(), subString.end());
        if (it != mainString.end()) {
            std::cout << "Substring founded at: " << std::distance(mainString.begin(), it) << std::endl;
            it += subString.length();
        }
    }

    return 0;
}
