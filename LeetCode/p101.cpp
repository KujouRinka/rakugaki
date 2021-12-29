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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            if (left->val != right->val)
                return false;
            bool b1 = dfs(left->left, right->right);
            bool b2 = dfs(left->right, right->left);
            return b1 && b2;
        }
        return false;
    }
};

