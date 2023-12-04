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
  TreeNode *bstToGst(TreeNode *root) {
    mp.fill(nullptr);
    dfs(root);

    int last_val = 0;
    for (int i = 100; i >= 0; --i) {
      if (mp[i] == nullptr) {
        continue;
      }
      last_val = (mp[i]->val += last_val);
    }
    return root;
  }

 private:
  array<TreeNode *, 101> mp;

  void dfs(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    mp[root->val] = root;
    dfs(root->right);
  }
};

