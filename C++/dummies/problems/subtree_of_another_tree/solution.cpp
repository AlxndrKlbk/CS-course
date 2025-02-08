#include <utility>
#include <queue>
#include <stack>
#include <vector>

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

    // O(N*M solution)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) {
            return false;
        }

        std::queue<TreeNode*> rootCandidates;
        rootCandidates.push(root);

        while (!rootCandidates.empty()) {
            auto cur = rootCandidates.front();
            rootCandidates.pop();
            if (!cur) {
                continue;
            }
            std::stack<std::pair<TreeNode*, TreeNode*>> nodeStack;
            nodeStack.push(std::make_pair(cur, subRoot));
            while(!nodeStack.empty()) {
                auto pair = nodeStack.top();
                auto parent = pair.first;
                auto child = pair.second;

                if(!parent && !child)
                {
                    nodeStack.pop();
                    continue;
                }else if (!parent || !child) {
                    break;
                }

                if (parent->val == child->val) {
                    nodeStack.pop();
                    nodeStack.push(std::make_pair(parent->left, child->left));
                    nodeStack.push(std::make_pair(parent->right, child->right));
                } else {
                    break;
                }
            }

            if (nodeStack.empty()) {
                return true;
            }

            rootCandidates.push(cur->left);
            rootCandidates.push(cur->right);
        }
        return false;
    }
};

/**
 * @brief The Solution2 class - find only nodes with expected depth and
 * check only them
 */
class Solution2 {
    std::vector<TreeNode*> nodes;

public:

    // O(N + M) solution
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;

        getDepth(s, getDepth(t, -1));

        for (TreeNode* n: nodes)
            if (identical(n, t))
                return true;

        return false;
    }

    /**
     * @brief getDepth
     * @param r - root off scanned tree
     * @param d - expected node depth
     * @param addNodes - flag for nodes collection
     * @return depth of node and side effect with collectoin nodes of expected depth
     */
    int getDepth(TreeNode* r, int d, bool addNodes = true) {
        if (!r)
            return -1;

        int depth = std::max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

        if (addNodes)
            nodes.push_back(r);

        return depth;
    }

    bool identical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
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
    node2_1.left = &node4_1;
    node2_1.right = &node5_1;

    TreeNode node1_2(4);
    TreeNode node2_2(1);
    TreeNode node3_2(2);

    node1_2.left = &node2_2;
    node1_2.right = &node3_2;


    Solution solution;
    auto&& res = solution.isSubtree(&node1_1, &node1_2);
    assert(res == true);

    node2_2.val = 3;
    res = solution.isSubtree(&node1_1, &node1_2);
    assert(res == false);

    return 0;
}
