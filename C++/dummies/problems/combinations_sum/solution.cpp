#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;
    }

private:
    void makeCombination(std::vector<int>& candidates, int target, int idx, std::vector<int>& comb, int total, std::vector<std::vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{2, 2, 3}, {7}};
    std::vector<int> nums{2, 3, 6, 7};
    int target = 7;

    Solution solution;
    auto res = solution.combinationSum(nums, target);
    assert(res.size() == inv.size());
    for (auto const& subset : res) {
        assert(std::find(inv.begin(), inv.end(), subset) != inv.end());
    }

    return 0;
}
