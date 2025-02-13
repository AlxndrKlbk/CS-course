#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <cassert>

// better runtime thanks for not using unordered set
class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();

        auto dfs = [&](int r, int c, int index, auto& dfs) -> bool {
            if (index == word.size()) {
                return true;
            }
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
                return false;
            }
            char temp = board[r][c];
            board[r][c] = '*'; // Mark as visited

            bool found = dfs(r + 1, c, index + 1, dfs) ||
                         dfs(r - 1, c, index + 1, dfs) ||
                         dfs(r, c + 1, index + 1, dfs) ||
                         dfs(r, c - 1, index + 1, dfs);

            board[r][c] = temp; // Restore the cell
            return found;
        };

        // reverse word for drop cases with search long word with one specific letter in end
        std::unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }

        if (count[word[0]] > count[word.back()]) {
            std::reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfs(r, c, 0, dfs)) return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();
        std::unordered_set<std::string> visited;

        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            if (k == word.length()) {
                return true;
            }

            if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(std::to_string(r) + "," + std::to_string(c)) || board[r][c] != word[k]) {
                return false;
            }

            visited.insert(std::to_string(r) + "," + std::to_string(c));
            bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(std::to_string(r) + "," + std::to_string(c));
            return res;
        };

        std::unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }

        if (count[word[0]] > count[word.back()]) {
            std::reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0, dfs)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main (int argc, char** argv)
{
    std::vector<std::vector<char>> nums{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution solution;
    auto res = solution.exist(nums, "ABCCED");
    assert(res == true);

    Solution2 solution2;
    res = solution2.exist(nums, "ABCCED");
    assert(res == true);

    return 0;
}
