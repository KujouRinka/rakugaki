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
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        previous = nullptr;
        return isValid(root);
    }

private:
    TreeNode *previous = nullptr;

    bool isValid(TreeNode *root) {
        if (root->left != nullptr && !isValid(root->left))
            return false;
        if (previous != nullptr && previous->val >= root->val)
            return false;
        previous = root;
        if (root->right != nullptr && !isValid(root->right))
            return false;
        return true;
    }
};

