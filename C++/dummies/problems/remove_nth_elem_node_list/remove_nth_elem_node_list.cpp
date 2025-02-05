#include <iostream>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr )
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp = nullptr;

        for(int i = 0; i < n ; i++)
            fast = fast->next;

        while (fast != nullptr) {
            tmp = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (tmp == nullptr) {
            return head->next;
        }

        tmp->next = slow->next;
        return head;
    }
 };

int main(int argc, char* argv[])
{
    if (argc < 3){
        const char x[] = "Hello World!";
        std::cout << x << std::endl;
    }

    int pos_from_end = atoi(argv[1]);

    ListNode node(atoi(argv[2]));
    ListNode* cur = &node, *tmp = nullptr;
    ListNode* head = cur;
    for (int i = 3; i < argc; i++){
        tmp = new ListNode(atoi(argv[i]));
        cur->next = tmp;
        cur = cur->next;
    }

    Solution solver;
    cur = solver.removeNthFromEnd(head, pos_from_end);

    while( cur != nullptr)
    {
        std::cout << (*cur).val << std::endl;
        cur = cur->next;
    }
    return 0;
}
