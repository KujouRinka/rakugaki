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

template<typename T>
T Max(T t1, T t2) {
  return std::max(t1, t2);
}

template<typename T, typename ...Args>
T Max(T t, Args... args) {
  return std::max(t, Max(args...));
}

class Solution {
 public:
  int rob(TreeNode *root) {
    int s1, s2;
    dfs(root, s1, s2);
    return max(s1, s2);
  }

 private:
  void dfs(TreeNode *root, int &rob_sum, int &no_rob_sum) {
    if (root == nullptr) {
      rob_sum = no_rob_sum = 0;
      return;
    }
    int ls1, ls2;
    int rs1, rs2;
    dfs(root->left, ls1, ls2);
    dfs(root->right, rs1, rs2);

    rob_sum = ls2 + rs2 + root->val;
    no_rob_sum = Max(ls1 + rs1, ls1 + rs2, ls2 + rs1, ls2 + rs2);
  }
};

