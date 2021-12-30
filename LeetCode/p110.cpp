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
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }

private:
    static int height(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left_h = height(root->left);
        int right_h = height(root->right);
        if (left_h == -1 || right_h == -1)
            return -1;
        return abs(left_h - right_h) <= 1 ? max(left_h, right_h) + 1 : -1;
    }
};

