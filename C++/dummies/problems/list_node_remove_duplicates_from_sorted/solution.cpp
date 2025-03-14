#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;

        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }

        return res;
    }
};

void case_1()
{
    ListNode first(1);
    ListNode second(1);
    ListNode third(2);
    ListNode fourth(3);
    ListNode five(3);

    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &five;
    five.next = nullptr;

    Solution solution;
    auto res = solution.deleteDuplicates(&first);
    assert(res->val == 1);
    assert(res->next->val == 2);
    assert(res->next->next->val == 3);
    assert(res->next->next->next == nullptr);
}

int main()
{
    case_1();

    return 0;
}

