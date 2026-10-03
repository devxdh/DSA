struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *c1, ListNode *c2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (c1 != nullptr && c2 != nullptr) {
            if (c1->val < c2->val) {
                tail->next = c1;
                c1 = c1->next;
            } else {
                tail->next = c2;
                c2 = c2->next;
            }
            tail = tail->next;
        }

        tail->next = c1 ? c1 : c2;

        return dummy->next;
    }
};
