#include <utility>
#include <stack>
#include <queue>
#include <unordered_map>
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

class SolutionRecursion {
public:
    int dia(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int lt = dia(root->left, ans);
        int rt = dia(root->right, ans);
        ans = std::max(ans, (lt+rt));
        return 1 + std::max(lt,rt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dia(root, ans);
        return ans;
    }
};

class Solution {
public:

    struct StackFrame {
        TreeNode* node;
        int left_height;
        int right_height;
        int& return_target;
    };

    int NOT_PROCESSED = -1;

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        std::stack<StackFrame> s;
        int _ = 0;
        s.push( { root, NOT_PROCESSED, NOT_PROCESSED, _ });

        while (!s.empty()) {
            auto [node, left_height, right_height, return_target] = s.top();

            if (!node) {
                return_target = 0;
                s.pop();
            } else if (left_height == NOT_PROCESSED) {
                s.push({ node->left, NOT_PROCESSED, NOT_PROCESSED, s.top().left_height });
            } else if (right_height == NOT_PROCESSED) {
                s.push({ node->right, NOT_PROCESSED, NOT_PROCESSED, s.top().right_height });
            }
            else {
                diameter = std::max(diameter, left_height+right_height);
                return_target = std::max(left_height, right_height) + 1;
                s.pop();
            }
        }
        return diameter;
    }
};

class SolutionMy {
public:

    // my implementation, it is work but gain time limit on large input trees
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root || (root && (!root->left && !root->right))) {
            return 0;
        }

        using NodeMark = std::pair<TreeNode*, int>;

        int diameter = 0;
        std::stack<TreeNode*> crossroads;
        std::queue<NodeMark> leftNodes;
        std::queue<NodeMark> rightNodes;
        crossroads.push(root);
        while (!crossroads.empty()) {
            auto crossroad = crossroads.top();
            crossroads.pop();
            if (!crossroad) {
                continue;
            }
            leftNodes.push(std::make_pair(crossroad->left, 1));
            rightNodes.push(std::make_pair(crossroad->right, 1));

            int long_left = 0;
            int long_right = 0;

            auto travers = [&diameter, &crossroads](std::queue<NodeMark>& nodes, int& longest) -> void {
                auto pair = nodes.front();
                auto lNode = pair.first;
                auto lNodeLenght = pair.second;
                nodes.pop();
                if (lNode){
                    if (!lNode->left && !lNode->right) {
                        longest = longest < lNodeLenght? lNodeLenght : longest;
                    } else if (lNode->left && lNode->right) {
                        crossroads.push(lNode);
                    }

                    if (lNode->left) {
                        nodes.push(std::make_pair(lNode->left, lNodeLenght + 1));
                    }
                    if (lNode->right) {
                        nodes.push(std::make_pair(lNode->right, lNodeLenght + 1));
                    }
                }
            };

            while (!leftNodes.empty()
                   || !rightNodes.empty())
            {
                if (!leftNodes.empty()) {
                    travers(leftNodes, long_left);
                }
                if (!rightNodes.empty()) {
                    travers(rightNodes, long_right);
                }
                int current_distance = long_left + long_right;
                diameter = diameter < current_distance? current_distance : diameter;
            }
        }
        return diameter;
    }
};

/**
 * @brief The SolutionMapStack class
 *  implement Breadth first search
 */
class SolutionMapStack {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        std::unordered_map<TreeNode*, int> map;
        std::stack<TreeNode*> stk;
        int diameter = 0;

        if (root != nullptr)
            stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();

            // Fill up stack to perform post-order traversal
            if (node->left != nullptr && map.find(node->left) == map.end()) {
                stk.push(node->left);
            } else if (node->right != nullptr && map.find(node->right) == map.end()) {
                stk.push(node->right);
            } else {

                // Process the root, once left and right sub-tree have been processed
                stk.pop();
                int leftDepth = map[node->left];
                int rightDepth = map[node->right];

                // Put the max depth at a node in the map
                map[node] = 1 + std::max(leftDepth, rightDepth);

                // Update the max diameter found so far
                diameter = std::max(diameter, leftDepth + rightDepth);
            }
        }
        return diameter;
    }
};

int main (int argc, char** argv)
{
    using clock = std::chrono::high_resolution_clock;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    Solution solution;
    auto start = clock::now();
    auto&& res = solution.diameterOfBinaryTree(&node1);
    auto stop = clock::now();
    std::cout << "Stack Frame implementatoin runtime:" << stop - start << std::endl;
    assert(res == 3);

    SolutionMy solution2;
    start = clock::now();
    res = solution2.diameterOfBinaryTree(&node1);
    stop = clock::now();
    std::cout << "Ugly Queue implementatoin runtime:" << stop - start << std::endl;
    assert(res == 3);

    SolutionMapStack solution3;
    start = clock::now();
    res = solution3.diameterOfBinaryTree(&node1);
    stop = clock::now();
    std::cout << "Stack and Map implementatoin runtime:" << stop - start << std::endl;
    assert(res == 3);

    SolutionRecursion solution4;
    start = clock::now();
    res = solution3.diameterOfBinaryTree(&node1);
    stop = clock::now();
    std::cout << "Recursion implementatoin runtime:" << stop - start << std::endl;
    assert(res == 3);

    return 0;
}
