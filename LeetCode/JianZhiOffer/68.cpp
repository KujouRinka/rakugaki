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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        _is_find = false;
        auto n = helper(root, p, q);
        if (_is_find)
            return n;
        return (p == n && q == root) || (q == n && p == root) ? root : nullptr;
    }

private:
    bool _is_find;

    TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;
        auto left = helper(root->left, p, q);
        auto right = helper(root->right, p, q);
        if (_is_find)
            return left ? left : right;
        if (((p == left || p == right) && q == root) || ((q == left || q == right) && p == root) || (left && right)) {
            _is_find = true;
            return root;
        }
        if (root == p || root == q)
            return root;
        return left ? left : right;
    }
};

