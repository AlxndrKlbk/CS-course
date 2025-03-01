#include <vector>

#include <cassert>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int prevRob = 0;
        int maxRob = 0;

        for (int curValue : nums) {
            int temp = std::max(maxRob, prevRob + curValue);
            prevRob = maxRob;
            maxRob = temp;
        }

        return maxRob;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {2, 10, 1, 2};
    Solution solution;
    auto res = solution.rob(nums);
    assert(res == 12);

    return 0;
}
