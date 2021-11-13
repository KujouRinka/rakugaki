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
    bool isBalanced(TreeNode *root) {
        return layer(root) != -1;
    }

private:
    static int layer(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left_layer = layer(root->left);
        int right_layer = layer(root->right);
        if (left_layer == -1 || right_layer == -1)
            return -1;
        if (abs(left_layer - right_layer) > 1)
            return -1;
        return max(left_layer, right_layer) + 1;
    }
};
