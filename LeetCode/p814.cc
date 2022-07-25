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
  TreeNode *pruneTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    bool b = allZero(root);
    return b ? nullptr : root;
  }

  bool allZero(TreeNode *root) {
    if (root == nullptr)
      return true;
    bool b2;
    bool b = b2 = allZero(root->left);
    if (b2)
      root->left = nullptr;
    b2 = allZero(root->right);
    b = b && b2;
    if (b2)
      root->right = nullptr;
    return root->val == 0 && b;
  }
};

