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
  int deepestLeavesSum(TreeNode *root) {
    _max_depth = 0;
    _ret = 0;
    helper(root, 0);
    return _ret;
  }

 private:
  int _max_depth;
  int _ret;

  void helper(TreeNode *root, int depth) {
    if (root == nullptr)
      return;
    if (_max_depth == depth) {
      _ret += root->val;
    } else if (_max_depth < depth) {
      _max_depth = depth;
      _ret = root->val;
    }
    helper(root->left, depth + 1);
    helper(root->right, depth + 1);
  }
};

