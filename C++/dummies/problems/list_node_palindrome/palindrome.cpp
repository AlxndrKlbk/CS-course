#include <stdio.h>
#include <assert.h>

//using namespace std;;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while( slow != NULL && slow->next != NULL )
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if( slow != NULL )
        {
            slow->next = prev;
        }
        fast = head;
        while( slow && fast ){
            if( slow->val != fast->val )
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

int main()
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(2);
    ListNode fourth(1);
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = nullptr;

    Solution solution;
    assert(solution.isPalindrome(&first) == true);

    return 0;
}

