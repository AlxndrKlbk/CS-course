
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        else if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            head = list1;
            list1 = list1->next;
        }
        ListNode* cursor = head;

        while( list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                cursor->next = list2;
                list2 = list2->next;
            }
            else {
                cursor->next = list1;
                list1 = list1->next;
            }
            cursor = cursor->next;
        }

        if( list1 == nullptr)
            cursor->next = list2;
        else
            cursor->next = list1;
        return head;
    }
};

int main() {
    ListNode head(1);
    ListNode second(2);
    head.next = &second;
    ListNode third(4);
    second.next = &third;

    ListNode head2(1);
    ListNode second2(3);
    head2.next = &second2;
    ListNode third2(4);
    second2.next = &third2;

    Solution solution;
    solution.mergeTwoLists(&head, &head2);
    return 0;
}
