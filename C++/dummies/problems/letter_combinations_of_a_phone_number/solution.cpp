#include <vector>
#include <string>

#include <cassert>

class Solution {
private:
    int mOffset = 2;
    std::vector<std::string> mChars = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void combine(std::vector<std::string>& res, std::vector<int> const& digits, int pos, std::string current) {
        if (digits.size() == pos) {
            res.push_back(current);
            return;
        }

        std::string letters = mChars[digits[pos] - mOffset];
        for (auto const& letter : letters) {
            combine(res, digits, pos + 1, current + letter);
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<int> converted;
        for (auto letter : digits) {
            converted.emplace_back(letter - '0');
        }
        std::vector<std::string> res;
        std::string current;
        combine(res, converted, 0, current);
        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<std::string> inv {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    Solution solution;
    auto res = solution.letterCombinations("23");
    assert(res == inv);

    return 0;
}
