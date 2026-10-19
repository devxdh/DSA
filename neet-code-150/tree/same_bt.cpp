#include <iostream>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    std::pair<TreeNode *, TreeNode *> equal_tree_maker() {
        TreeNode *p_root = new TreeNode(1);
        TreeNode *q_root = new TreeNode(1);

        p_root->left = new TreeNode(2);
        q_root->left = new TreeNode(2);

        p_root->right = new TreeNode(3);
        q_root->right = new TreeNode(3);

        return {p_root, q_root};
    }
};

int main() {
    Solution solver;

    auto [p, q] = solver.equal_tree_maker();

    bool result = solver.isSameTree(p, q);

    std::cout << result << std::endl;

    return 0;
}
