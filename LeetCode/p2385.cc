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
  int amountOfTime(TreeNode *root, int start) {
    this->start = start;
    r = 0;

    bool dummy;
    depth(root, dummy);

    return r;
  }

 private:
  int start;
  int r;

  int depth(TreeNode *node, bool &at_this) {
    at_this = false;
    if (node == nullptr) {
      return 0;
    }

    bool at_left, at_right;
    int ld = depth(node->left, at_left);
    int rd = depth(node->right, at_right);

    int cur_depth = max(ld, rd) + 1;

    if (node->val == start) {
      at_this = true;
      r = max(ld, rd);
      return 1;
    }

    if (at_left || at_right) {
      r = max(r, ld + rd);
      at_this = true;
      return (at_left ? ld : rd) + 1;
    }

    return cur_depth;
  }
};

