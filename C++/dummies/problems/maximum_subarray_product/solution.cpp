#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = *std::max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;

        for (int n : nums) {
            int temp = curMax * n;
            curMax = std::max({temp, curMin * n, n});
            curMin = std::min({temp, curMin * n, n});

            res = std::max(res, curMax);
        }

        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {2, 3, -2, 4};
    Solution solution;
    auto res = solution.maxProduct(nums);
    assert(res == 6);

    return 0;
}
