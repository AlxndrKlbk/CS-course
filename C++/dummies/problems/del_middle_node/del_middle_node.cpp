struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* prev = new ListNode;

        while( fast && fast->next )
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if( prev->next != nullptr)
        {
            prev->next = slow->next;
            return head;
        }
        else
        {
            return prev;
        }
    }
};

int main()
{
    ListNode head = ListNode( 1 );
    Solution solver = Solution();
    ListNode* ln_ptr = solver.deleteMiddle( &head );
    delete ln_ptr;
    return 0;
}

