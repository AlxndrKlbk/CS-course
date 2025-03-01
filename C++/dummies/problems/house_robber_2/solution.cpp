#include <vector>

#include <cassert>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prevRob = 0;
        int maxRob = 0;

        for (int i = 0; i <= nums.size() - 2; i++) {
            int temp = std::max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }

        int maxRob2 = 0;
        prevRob = 0;
        for (int i = 1; i < nums.size(); i++) {
            int temp = std::max(maxRob2, prevRob + nums[i]);
            prevRob = maxRob2;
            maxRob2 = temp;
        }
        return std::max(maxRob, maxRob2);
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {11, 10, 1, 12};
    Solution solution;
    auto res = solution.rob(nums);
    assert(res == 22);

    return 0;
}
