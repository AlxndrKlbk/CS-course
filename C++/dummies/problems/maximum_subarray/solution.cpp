#include <vector>

#include <cassert>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int res = nums[0];
        int total = 0;

        for (int n : nums) {
            if (total < 0) {
                total = 0;
            }

            total += n;
            res = std::max(res, total);
        }

        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    auto res = solution.maxSubArray(nums);
    assert(res == 6);

    return 0;
}
