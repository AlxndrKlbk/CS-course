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
    ListNode* removeElements(ListNode* head, int val)
    {
        if (head == nullptr) {
            return head;
        }

        while (head && head->val == val) {
            head = head->next;
        }

        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;
        ListNode* tmp = head->next;

        while (cur != nullptr) {
            if (tmp == nullptr) {
                cur->next = tmp;
                cur = cur->next;
            }
            else if (tmp->val != val)
            {
                cur->next = tmp;
                cur = cur->next;
                tmp = tmp->next;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return head;
    }
};

void case_1()
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(6);
    ListNode fourth(3);
    ListNode five(4);
    ListNode six(5);
    ListNode seven(6);

    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &five;
    five.next = &six;
    six.next = &seven;
    seven.next = nullptr;

    Solution solution;
    auto res = solution.removeElements(&first, 6);
    assert(res->val == 1);
    assert(res->next->val == 2);
    assert(res->next->next->val == 3);
    assert(res->next->next->next->val == 4);
    assert(res->next->next->next->next->val == 5);
}

void case_2 ()
{
    ListNode first(1);
    Solution solution;
    auto res = solution.removeElements(&first, 1);
    assert(res == nullptr);
}

int main()
{
    case_1();
    case_2();

    return 0;
}

