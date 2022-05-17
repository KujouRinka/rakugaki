/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        _n = k;
        dfs(root);
        return _result;
    }

private:
    int _n;
    int _result;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        dfs(root->right);
        if (_n == 0)
            return;
        --_n;
        if (_n == 0) {
            _result = root->val;
            return;
        }
        dfs(root->left);
    }
};

