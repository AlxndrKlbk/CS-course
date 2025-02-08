#include <utility>
#include <queue>

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

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        std::swap(root->left, root->right);
        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};

class Solution2 {
public:

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        std::queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            if (!node) {
                continue;
            }
            std::swap(node->left, node->right);
            nodes.push(node->left);
            nodes.push(node->right);
        }

        return root;
    }
};

int main (int argc, char** argv)
{
    TreeNode node1_1(3);
    TreeNode node2_1(4);
    TreeNode node3_1(5);
    TreeNode node4_1(1);
    TreeNode node5_1(2);

    node1_1.left = &node2_1;
    node1_1.right = &node3_1;
    node2_1.left = &node4_1;
    node2_1.right = &node5_1;

    Solution solution;
    auto&& res = solution.invertTree(&node1_1);
    assert(res->left->val == 5);
    assert(res->right->val == 4);
    assert(res->right->left->val == 2);
    assert(res->right->right->val == 1);

    solution.invertTree(&node1_1);

    Solution2 solution2;

    res = solution2.invertTree(&node1_1);
    assert(res->left->val == 5);
    assert(res->right->val == 4);
    assert(res->right->left->val == 2);
    assert(res->right->right->val == 1);

    return 0;
}
