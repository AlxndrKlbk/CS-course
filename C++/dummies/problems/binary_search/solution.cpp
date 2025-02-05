#include <vector>
#include <cassert>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int right = nums.size();
        if (!right) {
            return -1;
        }
        int left = 0;
        int&& res = -1;
        while(left <= right) {
            auto&& pos = (right + left) / 2;
            auto const& val = nums[pos];
            if (val == target) {
                res = pos;
                break;
            }

            if (val > target) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
        return res;
    }
};

int main (int argc, char** argv) {
    std::vector<int> nums = {-1,0,3,5,9,12};

    Solution solution;
    auto&& res = solution.search(nums, 9);
    assert(res == 4);

    res = solution.search(nums, 8);
    assert(res == -1);

    return 0;
}
