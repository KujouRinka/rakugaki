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
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode *previous = nullptr;
        TreeNode *current = root;
        while (current != nullptr && current->val != key) {
            previous = current;
            if (current->val > key)
                current = current->left;
            else
                current = current->right;
        }
        if (current == nullptr)
            return root;

        if (current->left != nullptr && current->right != nullptr) {
            TreeNode *sub_previous = current;
            TreeNode *sub_current = current->left;
            while (sub_current->right != nullptr) {
                sub_previous = sub_current;
                sub_current = sub_current->right;
            }
            current->val = sub_current->val;
            if (sub_previous == current)
                sub_previous->left = sub_current->left;
            else
                sub_previous->right = sub_current->left;
        } else if (current->left == nullptr) {
            if (current == root)
                return current->right;
            else
                (previous->left == current ? previous->left : previous->right) = current->right;
        } else if (current->right == nullptr) {
            if (current == root)
                return current->left;
            else
                (previous->left == current ? previous->left : previous->right) = current->left;
        } else {
            if (current == root)
                return nullptr;
            else
                (previous->left == current ? previous->left : previous->right) = nullptr;
        }
        return root;
    }
};

