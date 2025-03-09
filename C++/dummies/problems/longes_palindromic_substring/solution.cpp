#include <string>

#include <cassert>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);
            int max_len = std::max(odd, even);

            if (max_len > end - start) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(std::string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main (int argc, char** argv)
{
    std::string source{"cbbd"};
    Solution solution;
    auto res = solution.longestPalindrome(source);
    assert(res == "bb");

    return 0;
}
