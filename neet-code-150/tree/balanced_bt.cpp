#include <algorithm>
#include <cstdlib>
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
    bool isBalanced(TreeNode *root) {
        return dfs(root) != -1;
    }

  private:
    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int leftHeight = dfs(root->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = dfs(root->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + std::max(rightHeight, leftHeight);
    }
};
