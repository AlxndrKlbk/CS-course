#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr &&
               fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
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
    fourth.next = nullptr;

    Solution solution;
    auto const& res = solution.middleNode(&first);
    assert(res == &third);

    return 0;
}
