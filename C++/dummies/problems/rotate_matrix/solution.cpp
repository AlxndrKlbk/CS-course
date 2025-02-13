#include <vector>

#include <cassert>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        if (!matrix.size()) {
            return;
        }
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        // Y axis reverse
        for (int j = 0; j <= cols; j++) {
            for (int i = 0; i <= rows / 2; i++) {
                std::swap(matrix[i][j], matrix[rows-i][j]);
            }
        }

        // 45 angle reverse
        int reverse_start = 0;
        for (int i = reverse_start; i <= rows; i++) {
            for (int j = reverse_start; j <= cols; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
            reverse_start++;
        }
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<int>> nums{{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
    std::vector<std::vector<int>> invarinat{{15,13,2,5}, {14,3,4,1}, {12,6,8,9}, {16,7,10,11}};
    Solution solution;
    solution.rotate(nums);
    assert(nums == invarinat);

    return 0;
}
