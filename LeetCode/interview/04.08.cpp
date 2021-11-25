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
    TreeNode *result = nullptr;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return result;
    }

private:
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool f = (left && right) || ((root == p || root == q) && (left || right));
        if (f)
            result = root;
        return left || right || root == p || root == q;
    }
};
