#include <vector>
#include <list>

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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> res = {};
        std::list<TreeNode*> stack = {root};

        while(!stack.empty()) {
            res.push_back(0);
            int size = stack.size();
            for (int i = 0; i < size; i++) {
                auto current = stack.front();
                res.back() += current->val;
                if (current->left) {
                    stack.push_back(current->left);
                }
                if (current->right) {
                    stack.push_back(current->right);
                }
                stack.pop_front();
            }
            res.back() /= size;
        }
        return res;
    }
};


int main (int argc, char** argv) {
    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);

    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;

    Solution solution;
    auto const& res = solution.averageOfLevels(&node1);

    std::vector<double> invariant = {3.0,14.50,11.0};

    for (int i = 0; i < invariant.size(); i++) {
        assert(invariant[i] == res[i]);
    }

    return 0;
}
