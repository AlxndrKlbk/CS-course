#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:

    void backtrack(int start, std::vector<int>& comb,
                   std::vector<std::vector<int>>& res,
                   int n, int k)  {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int num = start; num <= n; num++) {
            comb.push_back(num);
            backtrack(num + 1, comb, res, n, k);
            comb.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(1, cur, res, n, k);
        return res;
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> inv{{1,2}, {1,3}, {1, 4}, {2,3}, {2, 4}, {3, 4}};
    Solution solution;

    auto res = solution.combine(4, 2);
    assert(res.size() == inv.size());
    for (auto const& subset : res) {
        assert(std::find(inv.begin(), inv.end(), subset) != inv.end());
    }

    return 0;
}
