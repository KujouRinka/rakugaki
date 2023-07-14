class Solution {
 public:
  int distributeCoins(TreeNode *root) {
    int cnt;
    int coins;
    return dfs(root, cnt, coins);
  }

 private:
  int dfs(TreeNode *root, int &cnt, int &coins) {
    if (root == nullptr) {
      cnt = coins = 0;
      return 0;
    }
    int c1, c2, co1, co2;
    int s1 = dfs(root->left, c1, co1);
    int s2 = dfs(root->right, c2, co2);
    cnt = c1 + c2 + 1;
    coins = co1 + co2 + root->val;
    return s1 + s2 + abs(cnt - coins);
  }
};

