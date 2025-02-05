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

class Solution
{
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();

            q1.pop();
            q2.pop();

            if(cur1 == nullptr && cur2 == nullptr)
            {
                continue;
            }
            if(cur1 == nullptr || cur2 == nullptr) return false;
            if(cur1->val != cur2->val) return false;

            q1.push(cur1->left);
            q2.push(cur2->left);
            q1.push(cur1->right);
            q2.push(cur2->right);
        }
        return true;
    }

    bool isSameTreeUgly(TreeNode* p, TreeNode* q) {
        if (!(p && q)) {
            return false;
        }

        std::queue<TreeNode*> back_p;
        back_p.push(p);
        std::queue<TreeNode*> back_q;
        back_q.push(q);

        while (!back_p.empty() && !back_q.empty())
        {
            auto size_p = back_p.size();
            auto size_q = back_q.size();

            if (size_p != size_q) {
                return false;
            }

            for (int i = 0; i < size_p; i++ )
            {
                auto cur_p = back_p.front();
                back_p.pop();
                auto cur_q = back_q.front();
                back_q.pop();

                if (cur_p->val != cur_q->val)
                {
                    return false;
                }

                if (cur_p->left && cur_q->left) {
                    back_p.push(cur_p->left);
                    back_q.push(cur_q->left);
                }
                if(cur_p->right && cur_q->right) {
                    back_p.push(cur_p->right);
                    back_q.push(cur_q->right);
                }
                if ((cur_p->left == nullptr && cur_q->left != nullptr) ||
                    (cur_p->left != nullptr && cur_q->left == nullptr) ||
                    (cur_p->right == nullptr && cur_q->right != nullptr) ||
                    (cur_p->right != nullptr && cur_q->right == nullptr))
                {
                    return false;
                }
            }
        }
        return true;
    }
};


int main (int argc, char** argv) {
    TreeNode node1_1(1);
    TreeNode node2_1(2);
    node1_1.left = &node2_1;
    node1_1.right = nullptr;

    TreeNode node1_2(1);
    TreeNode node2_2(2);
    node1_2.right = &node2_2;
    node1_2.left = nullptr;

    Solution solution;

    auto&& res = solution.isSameTreeUgly(&node1_1, &node1_2);
    assert(res == false);

    res = solution.isSameTree(&node1_1, &node1_2);
    assert(res == false);

    return 0;
}
