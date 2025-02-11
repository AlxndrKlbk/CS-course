#include <vector>

#include <cassert>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);

        int left = 1; // multiplication from left
        int right = 1; // multiplication from right
        for (int i = 0; i < nums.size(); i++) {
            res[i] *= left;
            left *= nums[i];
            res[nums.size() - i - 1] *= right;
            right *= nums[nums.size() - i - 1];
        }
        return res;
    }
};


int main (int argc, char** argv)
{
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<int> invariant{24, 12, 8, 6};
    Solution solution;
    auto const& res = solution.productExceptSelf(nums);
    assert(invariant == res);

    return 0;
}
