#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode  *prev = nullptr;
        while(head != nullptr) {
            ListNode *cur = head;
            head = head->next;
            cur->next = prev;
            prev = cur;
        }
        return prev;
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
    auto const& res = solution.reverseList(&first);
    assert(res == &fourth);
    assert(res->next == &third);
    assert(res->next->next == &second);
    assert(res->next->next->next == &first);
    assert(res->next->next->next->next == nullptr);

    return 0;
}
