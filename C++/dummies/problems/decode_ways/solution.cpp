#include <string>
#include <sys/types.h>
#include <vector>
#include <cassert>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();
        std::vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2, 2));

            if (1 <= one && one <= 9) {
                dp[i] += dp[i - 1];
            }
            if (10 <= two && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main (int argc, char** argv)
{
    Solution solution;
    auto res = solution.numDecodings("226");
    assert(res == 3);

    res = solution.numDecodings("22");
    assert(res == 2);

    return 0;
}
