#include <array>
#include <sys/types.h>
#include <vector>
#include <cassert>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::array<uint, 1000 + 1> dp{0};
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums{1,2,3};
    Solution solution;
    auto res = solution.combinationSum4(nums, 4);
    assert(res == 7);

    return 0;
}
