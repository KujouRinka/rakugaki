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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return help(root->left, root->right);
    }

private:
    bool help(TreeNode *n1, TreeNode *n2) {
        if (n1 == NULL && n2 == NULL)
            return true;
        if (n1 == NULL || n2 == NULL || n1->val != n2->val)
            return false;
        return help(n1->left, n2->right) && help(n1->right, n2->left);
    }
};

