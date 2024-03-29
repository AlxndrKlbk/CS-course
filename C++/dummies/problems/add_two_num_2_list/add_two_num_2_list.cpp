#include <memory>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = nullptr, *res_start = nullptr;
        ListNode* sum_node = new ListNode( 0 );
        res_start = sum_node;

        while( l1 || l2 )
        {
            if( l1 && l2)
            {
                sum_node->val += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if ( l1)
            {
                sum_node->val += l1->val;
                l1 = l1->next;
            }
            else if( l2 )
            {
                sum_node->val += l2->val;
                l2 = l2->next;
            }

            if( sum_node->val > 9 )
            {
                sum_node->val -= 10;
                sum_node->next = new ListNode( 1 );
            }
            else if( l1 || l2 )
                sum_node->next = new ListNode( 0 );
            else
                break;
            sum_node = sum_node->next;
        }
        return res_start;
    }
};

int main()
{
    ListNode* n1 = nullptr, *n2 = nullptr;
    Solution solver = Solution();
    n1 = new ListNode( 2 );
    n1->next = new ListNode( 4 );
    n1->next->next = new ListNode( 3 );
    n2 = new ListNode( 5 );
    n2->next = new ListNode( 6 );
    n2->next->next = new ListNode( 4 );
    auto* result = solver.addTwoNumbers( n1, n2 );
    while( result )
    {
        std::cout<< result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}
