#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};

int main (int argc, char** argv)
{

    std::vector<int> input{-7,-3,2,3,11};

    Solution solution;
    auto&& res = solution.sortedSquares(input);

    std::vector<int> expected{4,9,9,49,121};
    assert(res == expected);

    return 0;
}
