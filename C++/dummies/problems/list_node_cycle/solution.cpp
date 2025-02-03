#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr ||
            head->next == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        for (;;) {
            if (slow->next == nullptr ||
                fast->next == nullptr ||
                fast->next->next == nullptr)
            {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


int main (int argc, char** argv) {
    ListNode first(3);
    ListNode second(2);
    ListNode third(0);
    ListNode fourth(-4);

    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &second;

    Solution solution;
    auto const& res = solution.hasCycle(&first);
    assert(res == true);

    return 0;
}
