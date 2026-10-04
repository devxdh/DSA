#include <unordered_map>
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::unordered_map<Node *, Node *> record;
        record[nullptr] = nullptr;

        Node *curr = head;
        Node *new_head = nullptr;

        while (curr) {
            Node *nn = new Node(curr->val);

            if (!new_head) {
                new_head = nn;
            }

            record[curr] = nn;
            curr = curr->next;
        }

        Node *nc = new_head;
        curr = head;

        while (curr) {
            nc->next = record[curr->next];
            nc->random = record[curr->random];

            nc = nc->next;
            curr = curr->next;
        }

        return new_head;
    }
};
