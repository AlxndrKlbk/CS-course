#include <string>

#include <cassert>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        auto s_it = s.cbegin();
        auto t_it = t.cbegin();

        while(s_it != s.end() && t_it != t.end()) {
            if (*t_it == *s_it) {
                s_it++;
            }
            t_it++;
        }

        return s_it == s.end();
    }
};

int main() {
    Solution solution;
    auto res = solution.isSubsequence("axc", "afwfpsapxxcxc");
    assert(res == true);

    return 0;
}
