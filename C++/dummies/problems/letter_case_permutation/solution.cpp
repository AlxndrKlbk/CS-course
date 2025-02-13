#include <vector>
#include <string>
#include <stack>

#include <cassert>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s) {
        int str_size = s.size();
        std::vector<std::string> res;
        std::stack<std::pair<std::string, int>> movements;
        movements.push(make_pair(s, 0));
        while(movements.size()) {
            auto cur = movements.top();
            movements.pop();

            if (cur.second == str_size) {
                res.emplace_back(cur.first);
                continue;
            }

            if (isalpha(s[cur.second])) {
                cur.first[cur.second] = toupper(s[cur.second]);
                movements.push(make_pair(cur.first, cur.second + 1));
                cur.first[cur.second] = tolower(s[cur.second]);
                movements.push(make_pair(cur.first, cur.second + 1));
            } else {
                movements.push(make_pair(cur.first, cur.second + 1));
            }
        }
        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<std::string> inv{"a1b2","a1B2","A1b2","A1B2"};
    Solution solution;
    auto res = solution.letterCasePermutation("a1b2");
    assert(res == inv);

    inv = {"c", "C"};
    res = solution.letterCasePermutation("C");
    assert(inv == res);

    return 0;
}
