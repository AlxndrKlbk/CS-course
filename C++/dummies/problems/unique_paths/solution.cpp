#include <array>
#include <cassert>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::array<std::array<int, 101>, 101> dp{0};
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int top = j - 1 >=0 ?  dp[i][j - 1] : 0;
                dp[i][j] = left + top;
            }
        }

        return dp[m-1][n-1];
    }
};

int main (int argc, char** argv)
{
    Solution solution;
    auto res = solution.uniquePaths(3, 7);
    assert(res == 28);

    return 0;
}
