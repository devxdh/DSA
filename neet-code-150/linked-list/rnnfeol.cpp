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
        std::vector<ListNode *> vec;

        ListNode *curr = head;
        while (curr != nullptr) {
            vec.push_back(curr);
            curr = curr->next;
        }

        ListNode *target = vec[vec.size() - n];
        if (target == head) {
            head = head->next;
        } else if (target->next == nullptr) {
            vec[vec.size() - n - 1]->next = nullptr;
        } else {
            vec[vec.size() - n - 1]->next = target->next;
        }

        return head;
    }
};
