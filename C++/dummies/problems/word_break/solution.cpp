#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (const std::string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main (int argc, char** argv)
{
    std::string source{"leetcode"};
    std::vector<std::string> wordToBreak{"leet", "code"};
    Solution solution;
    auto res = solution.wordBreak(source, wordToBreak);
    assert(res == true);

    source = "a";
    wordToBreak = {"a"};
    res = solution.wordBreak(source, wordToBreak);
    assert(res == true);

    source = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordToBreak = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    res = solution.wordBreak(source, wordToBreak);
    assert(res == false);

    return 0;
}
