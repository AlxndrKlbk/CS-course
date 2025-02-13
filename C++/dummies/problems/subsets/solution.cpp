#include <vector>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;
    }

    void createSubset(std::vector<int>& nums, int index, std::vector<std::vector<int>>& res, std::vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{1,2,3},{1,2},{1,3},{1},{2,3},{2},{3},{}};
    std::vector<int> nums{1,2,3};
    Solution solution;

    auto res = solution.subsets(nums);
    assert(res == inv);

    return 0;
}
