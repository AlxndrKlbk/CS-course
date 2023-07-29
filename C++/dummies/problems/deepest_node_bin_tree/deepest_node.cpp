#include <vector>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


typedef pair< TreeNode*, int> node_index;
typedef vector< node_index > node_stack;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( root == nullptr )
            return 0;

        node_stack stack;
        int max_depth = 1, depth = 1;
        TreeNode* cursor = root;
        node_index index = {cursor, depth};
        stack.push_back( index  );

        while( stack.size() != 0 )
        {
            index = *stack.erase( stack.end() - 1 );
            cursor = index.first;
            depth = index.second;
            if( cursor->left != nullptr)
            {
                stack.push_back({cursor->left, depth + 1});
            }
            if( cursor->right != nullptr)
            {
                stack.push_back({cursor->right, depth + 1});
            }

            if( depth > max_depth )
            {
                max_depth = depth;
            }
        }

        return max_depth;
    }
};

int main()
{
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);

    node1.right = &node2;
    int result;
    Solution solver;
    result = solver.maxDepth( &node1 );

    cout << result << endl;
    return 0;
}
