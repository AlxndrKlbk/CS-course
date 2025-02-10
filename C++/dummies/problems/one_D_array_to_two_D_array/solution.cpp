#include <vector>

#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }

        std::vector<std::vector<int>> res(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                auto pos = i * n + j;
                res[i][j] = original[pos];
            }
        }
        return res;
    }
};

int main() {
    static const std::vector<std::vector<int>> invariant{{1, 1}, { 3, 0}};

    std::vector<int> nums {1, 1, 3, 0};
    Solution solution;
    auto res = solution.construct2DArray(nums, 2, 2);
    assert(res == invariant);

    return 0;
}
