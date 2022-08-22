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
  vector<vector<string>> printTree(TreeNode *root) {
    int height = getHeight(root);
    int max_line = static_cast<int>(pow(2, height)) - 1;
    _ret = vector<vector<string>>(height, vector<string>(max_line));
    fill(root, 0, max_line - 1, 0);
    return _ret;
  }

 private:
  vector<vector<string>> _ret;

  int getHeight(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  void fill(TreeNode *root, int left, int right, int height) {
    if (root == nullptr || left > right)
      return;
    int fill_pos = (left + right) >> 1;
    _ret[height][fill_pos] = to_string(root->val);
    fill(root->left, left, fill_pos - 1, height + 1);
    fill(root->right, fill_pos + 1, right, height + 1);
  }
};

