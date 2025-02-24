#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end) {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start)); // substr(start_pos, size_t len)
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};


int main (int argc, char** argv)
{

    vector<vector<string>> inv = {{"a", "a", "a"}, {"aa", "a"}, {"a", "aa"}};

    Solution sol;
    auto const& res = sol.partition({"aaa"});
    for (auto const& val : inv) {
        assert(std::find(res.begin(), res.end(), val) != res.end());
    }
    return 0;
}
