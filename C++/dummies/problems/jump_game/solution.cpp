#include <vector>
#include <cassert>

class Solution {
public:
    bool canJump2(std::vector<int>& nums) {
        if (nums[0] == 0 && nums.size() == 1) {
            return true;
        } else if (nums[0] == 0) {
            return false;
        }

        std::vector<bool> visited(nums.size(), false);
        visited[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; ((j < nums[i] + i) && (j < nums.size())) || (j == nums.size() - 1 && j == nums[i] + i); j++)  {
                visited[j] = true;
            }
        }

        for (auto val : visited) {
            if (!val) {
                return false;
            }
        }

        return true;
    }

    bool canJump(std::vector<int>& nums) {
        int visited_index = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= visited_index) {
                visited_index = i;
            }
        }

        return visited_index == 0;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums = {2, 0, 0};
    Solution solution;
    auto res = solution.canJump(nums);
    assert(res == true);

    return 0;
}
