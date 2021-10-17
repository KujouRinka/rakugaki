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
    int kthSmallest(TreeNode *root, int k) {
        return dfs(root, k);
    }

private:
    static int dfs(TreeNode *root, int &n) {
        if (root == nullptr)
            return -1;
        int v;
        v = dfs(root->left, n);
        if (v != -1)
            return v;
        n--;
        if (n == 0)
            return root->val;
        v = dfs(root->right, n);
        if (v != -1)
            return v;
        return -1;
    }
};
