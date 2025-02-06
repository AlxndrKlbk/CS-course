#include <utility>
#include <stack>

#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int deepest = 0;
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push(std::make_pair(root, 1));
        while (!stack.empty()) {
            auto cur = stack.top();
            stack.pop();
            auto&& node = cur.first;
            auto&& depth = cur.second;
            if (!node) {
                continue;
            }

            if (!node->left && !node->right) {
                deepest = deepest < depth ? depth : deepest;
            }

            if (node->left) {
                stack.push(std::make_pair(node->left, depth + 1));
            }
            if (node->right) {
                stack.push(std::make_pair(node->right, depth + 1));
            }
        }
        return deepest;
    }
};


int main (int argc, char** argv)
{
    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);

    node1.left = &node2;
    node2.right = &node3;
    node3.right = &node4;
    node4.left = &node5;

    Solution solution;
    auto const&& res = solution.maxDepth(&node1);
    assert(res == 5);
    return 0;
}
