#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        std::vector<ListNode *> listVec;

        ListNode *curr = head;
        while (curr != nullptr) {
            listVec.push_back(curr);
            curr = curr->next;
        }

        ListNode *target = listVec[(listVec.size() - n)];
        if (target == head) {
            head = head->next;
            return head;
        } else if (target->next == nullptr) {
            listVec[(listVec.size() - n - 1)]->next = nullptr;
            return head;
        } else {
            listVec[(listVec.size() - n - 1)]->next = target->next;
            return head;
        }
    }
};
