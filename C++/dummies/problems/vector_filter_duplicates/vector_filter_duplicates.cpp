#include <cstdlib>

#include <unordered_set>
#include <vector>
#include <iostream>

class Solution {
public:
    static bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;

        for (auto const& val : nums) {
            if (s.find(val) != s.end()) {
                return true;
            }
            s.insert(val);
        }

        return false;

    }
};


int main(int argc, char** argv)
{
    char* inputChar = nullptr;
    std::vector<int> buff;
    for (int i = 1; i < argc; i++)
    {
        inputChar = argv[i];
        buff.emplace_back(atoi(inputChar));
    }

    std::cout << Solution::hasDuplicate(buff) << std::endl;

    return 0;
}
