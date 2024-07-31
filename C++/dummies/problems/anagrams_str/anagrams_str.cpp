#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    static bool isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) return false;

        std::unordered_map<char, int> charDict;

        for(auto const chr: s)
        {
            charDict[chr]++;
        }

        for(auto const chr: t)
        {
            if (charDict.find(chr) == charDict.end()) {
                return false;
            }

            charDict[chr]--;
            if (charDict[chr] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    std::cout << Solution::isAnagram(argv[1], argv[2]) << std::endl;

    return 0;
}
