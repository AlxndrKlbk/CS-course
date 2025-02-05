#include <cassert>
#include <sys/types.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        } else if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        if (list1->val <= list2->val) {
            res = list1;
            cur = list1;
            list1 = list1->next;
        } else {
            res = list2;
            cur = list2;
            list2 = list2->next;
        }

        while (list1 && list2)
        {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (!list1) {
            cur->next = list2;
        } else if (!list2) {
            cur->next = list1;
        }
        return res;
    }
};

int main (int argc, char** argv) {
    ListNode first_1(0);
    ListNode second_1(2);
    ListNode third_1(3);
    ListNode fourth_1(5);

    first_1.next = &second_1;
    second_1.next = &third_1;
    third_1.next = &fourth_1;
    fourth_1.next = nullptr;

    ListNode first_2(1);
    ListNode second_2(2);
    ListNode third_2(4);
    ListNode fourth_2(6);

    first_2.next = &second_2;
    second_2.next = &third_2;
    third_2.next = &fourth_2;
    fourth_2.next = nullptr;

    Solution solution;
    auto const& res = solution.mergeTwoLists(&first_1, &first_2);

    constexpr int invariant[] = {0, 1, 2, 2, 3, 4, 5, 6};
    auto cur = res;
    uint counter = 0;
    while(cur) {
        assert(cur->val == invariant[counter]);
        counter++;
        cur = cur->next;
    }

    return 0;
}
