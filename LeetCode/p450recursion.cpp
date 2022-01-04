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
        if (root == nullptr)
            return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->left != nullptr && root->right != nullptr) {
            if (isLeaf(root->left)) {
                root->val = root->left->val;
                root->left = nullptr;
            } else {
                TreeNode *sub_previous = root;
                TreeNode *sub_current = root->left;
                while (sub_current->right != nullptr) {
                    sub_previous = sub_current;
                    sub_current = sub_current->right;
                }
                root->val = sub_current->val;
                if (sub_previous == root)
                    sub_previous->left = sub_current->left;
                else
                    sub_previous->right = sub_current->left;
            }
            return root;
        } else if (root->left == nullptr) { // && root->right != nullptr
            return root->right;
        } else if (root->right == nullptr) {    // && root->left != nullptr
            return root->left;
        } else {    // root->left == nullptr && root->right == nullptr
            return nullptr;
        }
    }

private:
    static inline bool isLeaf(TreeNode *root) {
        return root->left == nullptr && root->right == nullptr;
    }
};

