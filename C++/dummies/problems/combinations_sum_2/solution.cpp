#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;

        std::vector<int> comb;
        dfs(candidates, target, 0, comb, res);
        return res;
    }

    void dfs(std::vector<int>& candidates, int target, int start, std::vector<int>& comb, std::vector<std::vector<int>>& res) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, comb, res);
            comb.pop_back();
        }
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{1,1,6}, {1,2,5}, {1,7}, {2,6}};
    std::vector<int> nums{10,1,2,7,6,1,5};
    int target = 8;

    Solution solution;
    auto res = solution.combinationSum2(nums, target);
    assert(res.size() == inv.size());
    for (auto const& subset : res) {
        assert(std::find(inv.begin(), inv.end(), subset) != inv.end());
    }

    return 0;
}
