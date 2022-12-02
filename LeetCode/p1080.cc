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
  using ll = long long;
 public:
  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    if (root != nullptr && helper(root, limit, 0) >= limit) {
      drop(root);
      return root;
    }
    return nullptr;
  }

 private:
  // return max sum of child tree
  ll helper(TreeNode *root, int limit, ll upper_sum) {
    ll new_upper_sum = upper_sum + root->val;
    ll left = 0, right = 0;
    bool drop_l = false, drop_r = false;
    if (root->left) {
      left = helper(root->left, limit, new_upper_sum);
      if (left + new_upper_sum < limit)
        drop_l = true;
    }
    if (root->right) {
      right = helper(root->right, limit, new_upper_sum);
      if (right + new_upper_sum < limit)
        drop_r = true;
    }
    ll ret;
    if (root->left && root->right)
      ret = max(left, right) + root->val;
    else
      ret = (root->left != nullptr ? left : right) + root->val;
    if (drop_l) {
      drop(root->left);
      root->left = nullptr;
    }
    if (drop_r) {
      drop(root->right);
      root->right = nullptr;
    }
    return ret;
  }

  void drop(TreeNode *root) {
    // do drop jobs
  }
};

