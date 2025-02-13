#include <vector>

#include <cassert>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols-1, top = 0, bottom = rows-1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};


int main (int argc, char** argv)
{
    std::vector<std::vector<int>> nums{{1, 0, 2}, {5, 5, 6}, {1, 1, 1}};
    std::vector<int> invarinat{1, 0, 2, 6, 1, 1, 1, 5, 5};
    Solution solution;
    auto const& res = solution.spiralOrder(nums);
    assert(res == invarinat);

    return 0;
}
