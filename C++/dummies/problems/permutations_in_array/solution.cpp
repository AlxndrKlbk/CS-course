#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(res, 0, nums);
        return res;
    }

private:
    void backtrack(std::vector<std::vector<int>>& res, int pos, std::vector<int>& nums) {
        if (pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            std::swap(nums[pos], nums[i]);
            backtrack(res, pos + 1, nums);
            std::swap(nums[pos], nums[i]);
        }
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};
    std::vector<int> nums{1, 2, 3};
    Solution solution;

    auto res = solution.permute(nums);
    assert(res.size() == inv.size());
    for (auto const& subset : res) {
        assert(std::find(inv.begin(), inv.end(), subset) != inv.end());
    }

    return 0;
}
