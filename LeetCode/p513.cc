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
  int findBottomLeftValue(TreeNode *root) {
    max_depth = -1;
    helper(root, 0);
    return ret;
  }

 private:
  int ret;
  int max_depth;
  
  void helper(TreeNode *root, int depth) {
    if (root == nullptr)
      return;
    if (depth > max_depth) {
      ret = root->val;
      max_depth = depth;
    }
    helper(root->left, depth + 1);
    helper(root->right, depth + 1);
  }
};

