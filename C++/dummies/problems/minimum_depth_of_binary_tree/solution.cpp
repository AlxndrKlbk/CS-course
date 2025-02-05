#include <chrono>
#include <iostream>
#include <list>
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
    int minDepthList(TreeNode* root) {
        if (!root) {
            return 0;
        } else if (!root->left && !root->right) {
            return 1;
        }

        int cur_depth = 0;
        std::list<TreeNode *> stack{root};
        while (!stack.empty()) {
            cur_depth++;
            auto size = stack.size();
            for (int i = 0; i < size; i++) {
                auto cur = stack.front();
                if (!cur->left && !cur->right) {
                    return cur_depth;
                }
                if (cur->left) {
                    stack.push_back(cur->left);
                }
                if (cur->right) {
                    stack.push_back(cur->right);
                }
                stack.pop_front();
            }
        }
        return cur_depth;
    }

    int minDepthQueue(TreeNode* root) {
        if(!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);
        int level=0;

        while(!q.empty()){

            int size=q.size();
            level++;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(!node->left && !node->right){
                    return level;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return level;
    }
};

int main (int argc, char** argv)
{
    using clock = std::chrono::high_resolution_clock;
    constexpr int invariant = 2;

    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);

    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;

    auto start = clock::now();
    Solution solution;
    auto&& res = solution.minDepthList(&node1);
    auto stop = clock::now();
    assert(invariant == res);
    std::cout << "List implementation runtime:" << stop - start << std::endl;

    start = clock::now();
    res = solution.minDepthQueue(&node1);
    stop = clock::now();
    assert(invariant == res);
    std::cout << "Queue implementation runtime:" << stop - start << std::endl;

    return 0;
}
