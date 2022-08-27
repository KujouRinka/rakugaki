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
  using ull = unsigned long long;
 public:
  int widthOfBinaryTree(TreeNode *root) {
    dfs(root, 0, 1);
    int ret = 0;
    for_each(_memo.begin(), _memo.end(), [&ret](auto &p) {
      ret = max<ull>(ret, p.second - p.first + 1);
    });
    return ret;
  }

 private:
  vector<pair<ull, ull>> _memo;

  void dfs(TreeNode *root, int depth, ull your_no) {
    if (root == 0)
      return;
    if (_memo.size() <= depth)
      _memo.resize(depth + 1);
    if (ull &first = _memo[depth].first; first == 0 || your_no < first)
      first = your_no;
    ull &second = _memo[depth].second;
    second = max(second, your_no);
    dfs(root->left, depth + 1, your_no << 1);
    dfs(root->right, depth + 1, (your_no << 1) + 1);
  }
};

