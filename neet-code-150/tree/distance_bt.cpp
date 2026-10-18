#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return res;
    }

  private:
    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = std::max(res, left + right);

        return 1 + std::max(left, right);
    }
};
