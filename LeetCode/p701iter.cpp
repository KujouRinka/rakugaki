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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        TreeNode *current = root;
        TreeNode *previous = current;
        while (current != nullptr) {
            previous = current;
            if (current->val > val)
                current = current->left;
            else if (current->val < val)
                current = current->right;
            else
                return current;
        }
        TreeNode *new_node = new TreeNode(val);
        if (previous->val > val)
            previous->left = new_node;
        else
            previous->right = new_node;
        return root;
    }
};

