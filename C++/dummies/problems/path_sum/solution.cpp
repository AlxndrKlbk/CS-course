#include <deque>
#include <set>
#include <utility>
#include <stack>
#include <chrono>

#include <iostream>
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

    // DFS recursive solution
    bool hasPathSumRecursion(TreeNode* root, int targetSum)
    {
        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL && root->val==targetSum){
            return true;
        }

        return hasPathSumRecursion(root->left, targetSum - root->val) || hasPathSumRecursion(root->right, targetSum - root->val);
    }

    bool hasPathSumStackDFS(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        std::stack<std::pair<TreeNode*,int>> s;
        s.push(std::make_pair(root, root->val));
        while(!s.empty()){
            std::pair<TreeNode*, int> top = s.top();
            s.pop();
            TreeNode* node = top.first;
            int currSum = top.second;

            if(node->left == NULL && node->right == NULL && currSum == targetSum){
                return true;
            }

            if(node->right != NULL){
                s.push(std::make_pair(node->right, currSum + node->right->val));
            }
            if(node->left != NULL){
                s.push(std::make_pair(node->left, currSum + node->left->val));
            }
        }
        return false;
    }

    // my ugly combination DFS + stack
    bool hasPathSumStackDFSUgly(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        std::deque<TreeNode*> dfs_stack;
        std::set<TreeNode*> path;

        dfs_stack.push_back(root);

        int path_sum = 0;
        while (!dfs_stack.empty())
        {
            auto cur = dfs_stack.back();
            if (cur == nullptr) {
                dfs_stack.pop_back();
                continue;
            }

            if (path.find(cur) != path.end()) {
                path_sum -= cur->val;
                path.erase(cur);
                dfs_stack.pop_back();
                continue;
            }

            path_sum += cur->val;

            if (!cur->left && !cur->right) {
                if (path_sum == targetSum) {
                    return true;
                } else {
                    path_sum -= cur->val;
                    path.erase(cur);
                    dfs_stack.pop_back();
                    continue;
                }
            }

            path.emplace(cur);
            dfs_stack.push_back(cur->right);
            dfs_stack.push_back(cur->left);
        }
        return false;
    }
};

using classMethodPtr = bool (Solution::*)(TreeNode*, int);

void test_1(Solution& solution, classMethodPtr func)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;

    auto&& res = (solution.*func)(&node1, 5);
    assert(res == false);
}

void test_2(Solution& solution, classMethodPtr func)
{
    TreeNode node1(1);
    TreeNode node2(2);
    node1.left = &node2;

    auto&& res = (solution.*func)(&node1, 0);
    assert(res == false);
}

void test_3(Solution& solution, classMethodPtr func)
{
    TreeNode node1(1);
    TreeNode node2(-2);
    TreeNode node3(1);
    TreeNode node4(-1);
    TreeNode node5(3);
    TreeNode node6(-3);
    TreeNode node7(-2);
    node1.left = &node2;
    node1.right = &node6;
    node2.left = &node3;
    node2.right = &node5;
    node3.left = &node4;
    node6.left = &node7;

    auto&& res = (solution.*func)(&node1, 3);
    assert(res == false);
}

int main (int argc, char** argv)
{
    Solution solution;
    using timer = std::chrono::high_resolution_clock;

    auto&& start = timer::now();
    test_1(solution, &Solution::hasPathSumStackDFS);
    test_2(solution, &Solution::hasPathSumStackDFS);
    test_3(solution, &Solution::hasPathSumStackDFS);
    auto&& stop = timer::now();
    std::cout << "Stack DFS implementation runtime:" << stop - start << std::endl;

    start = timer::now();
    test_1(solution, &Solution::hasPathSumStackDFSUgly);
    test_2(solution, &Solution::hasPathSumStackDFSUgly);
    test_3(solution, &Solution::hasPathSumStackDFSUgly);
    stop = timer::now();
    std::cout << "Ugly stack DFS implementation runtime:" << stop - start << std::endl;

    start = timer::now();
    test_1(solution, &Solution::hasPathSumRecursion);
    test_2(solution, &Solution::hasPathSumRecursion);
    test_3(solution, &Solution::hasPathSumRecursion);
    stop = timer::now();
    std::cout << "Recursive DFS implementation runtime:" << stop - start << std::endl;

    return 0;
}
