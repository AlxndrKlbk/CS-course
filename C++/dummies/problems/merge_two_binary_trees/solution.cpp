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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        } else if (!root1) {
            return root2;
        } else if (!root2) {
            return root1;
        }

        auto result = root1;
        std::queue<std::pair<TreeNode*, TreeNode*>> dfs;
        dfs.push(std::make_pair(root1, root2));
        while (!dfs.empty()) {
            auto cur_pair = dfs.front();
            dfs.pop();
            auto node1 = cur_pair.first;
            auto node2 = cur_pair.second;
            if (!node1 && !node2) {
                continue;
            } else if ((node1 && node2)) {
                node1->val += node2->val;

                if (!node1->left && node2->left) {
                    node1->left = node2->left;
                    node2->left = nullptr;
                }
                if (!node1->right && node2->right) {
                    node1->right = node2->right;
                    node2->right = nullptr;
                }
                dfs.push(std::make_pair(node1->left, node2->left));
                dfs.push(std::make_pair(node1->right, node2->right));
            }

        }
        return root1;
    }
};


int main (int argc, char** argv)
{
    TreeNode node1_1(1);
    TreeNode node2_1(3);
    TreeNode node3_1(2);
    TreeNode node4_1(5);

    node1_1.left = &node2_1;
    node1_1.right = &node3_1;
    node2_1.left = &node4_1;

    TreeNode node1_2(2);
    TreeNode node2_2(1);
    TreeNode node3_2(3);
    TreeNode node4_2(4);
    TreeNode node5_2(7);

    node1_2.left = &node2_2;
    node1_2.right = &node3_2;
    node2_2.right = &node4_2;
    node3_2.right = &node5_2;


    Solution solution;
    auto const&& res = solution.mergeTrees(&node1_1, &node1_2);
    assert(res->val == 3);
    assert(res->left->val == 4);
    assert(res->right->val == 5);
    assert(res->left->left->val == 5);
    assert(res->left->right->val == 4);
    assert(res->right->right->val == 7);
    return 0;
}
