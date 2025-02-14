#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, result);
        return result;
    }

    void backtrack(std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{}, {1}, {1,2}, {1,2,2}, {2}, {2,2}};
    std::vector<int> nums{1,2,2};
    Solution solution;

    auto res = solution.subsetsWithDup(nums);
    assert(res == inv);

    return 0;
}
