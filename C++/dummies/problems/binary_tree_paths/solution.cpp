#include <unordered_map>
#include <stack>
#include <vector>
#include <string>
#include <chrono>

#include <iostream>
#include <cassert>

using timer = std::chrono::high_resolution_clock;

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
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        } else if (!root->left && !root->right) {
            return {std::to_string(root->val)};
        }

        std::stack<TreeNode*> nodes;
        nodes.push(root);
        std::unordered_map<TreeNode*, TreeNode*> links;
        std::vector<std::string> res;

        auto save_path = [&links, &res, &root] (TreeNode* leaf) {
            std::string str_path{std::to_string(leaf->val)};
            auto parent = links.find(leaf);
            while(parent->second != root) {
                str_path = std::to_string(parent->second->val) +  "->" + str_path;
                parent = links.find(parent->second);
            }
            res.push_back(std::to_string(parent->second->val) + "->" + str_path);
        };

        while(!nodes.empty()) {
            auto cur = nodes.top();
            nodes.pop();
            if (!cur) {
                continue;
            }

            if (!cur->left && !cur->right) {
                save_path(cur);
                continue;
            }

            links[cur->left] = cur;
            links[cur->right] = cur;
            nodes.push(cur->right);
            nodes.push(cur->left);
        }
        return res;
    }
};


void test(Solution& solution)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;

    const std::vector<std::string> invariant = {"1->2->5","1->3"};

    auto&& start = timer::now();
    auto&& res = solution.binaryTreePaths(&node1);
    auto&& stop = timer::now();
    std::cout << "Stack DFS+Unordered_map implementation runtime:" << stop - start << std::endl;

    assert(res[0] == invariant[0]);
    assert(res[1] == invariant[1]);
}

int main (int argc, char** argv)
{
    Solution solution;
    test(solution);
    return 0;
}
