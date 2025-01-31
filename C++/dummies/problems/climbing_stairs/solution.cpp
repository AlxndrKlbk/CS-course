#include <vector>

#include <cassert>

class Solution {
public:

    /**
     * @brief climbStairs - ways of movement to N step is sum ways to (n-1) and  ways (n+2)
     * @param n - steps to stair
     * @return count of distinct ways
     */
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int n_minus_1_ways = 1, n_minus_2_ways = 2;
        for (int i = 3; i <= n; i++) {
            int n_ways = n_minus_1_ways + n_minus_2_ways;
            n_minus_1_ways = n_minus_2_ways;
            n_minus_2_ways = n_ways;
        }
        return n_minus_2_ways;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vec = {4,1,2,1,2};

    auto solution = Solution();
    auto&& res = solution.climbStairs(5);
    assert(res == 7);
    return 0;
}
