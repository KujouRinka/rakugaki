/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int goodNodes(TreeNode *root) {
    return good_nodes_next(root, -0x7fffffff);
  }

 private:
  int good_nodes_next(TreeNode *root, int memo) {
    if (root == nullptr) {
      return 0;
    }
    return good_nodes_next(root->left, max(root->val, memo)) +
        good_nodes_next(root->right, max(root->val, memo)) + (root->val < memo ? 0 : 1);
  }
};

