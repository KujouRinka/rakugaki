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
  int countNodes(TreeNode *root) {
    int ret = 0;
    while (root) {
      int ld = getDepth(root->left);
      int rd = getDepth(root->right);
      if (ld == rd) {
        ret += (1 << ld);
        root = root->right;
      } else {
        ret += (1 << rd);
        root = root->left;
      }
    }
    return ret;
  }

 private:
  int getDepth(TreeNode *root) {
    int ret = 0;
    while (root) {
      ++ret;
      root = root->left;
    }
    return ret;
  }
};

