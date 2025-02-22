#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
private:
    void func(int index, std::vector<int>& comb, int sum, int k, int n, std::vector<std::vector<int>>& ans, std::vector<int>& nums) {
        if (sum == 0 && comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        if (sum < 0 || index == n || comb.size() == k) {
            return;
        }
        comb.push_back(nums[index]);
        func(index + 1, comb, sum - nums[index], k, n, ans, nums);
        comb.pop_back();
        func(index + 1, comb, sum, k, n, ans, nums);
    }

public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int sz = 9;
        std::vector<int> comb;
        std::vector<std::vector<int>> res;
        func(0, comb, n, k, sz, res, nums);
        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{1, 2, 4}};
    std::vector<int> nums{10,1,2,7,6,1,5};

    Solution solution;
    auto res = solution.combinationSum3(3, 7);
    assert(res.size() == inv.size());
    for (auto const& subset : res) {
        assert(std::find(inv.begin(), inv.end(), subset) != inv.end());
    }

    return 0;
}
