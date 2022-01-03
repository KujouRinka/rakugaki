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
    int getMinimumDifference(TreeNode *root) {
        previous = nullptr;
        result = 0x7fffffff;
        getMin(root);
        return result;
    }

private:
    TreeNode *previous = nullptr;
    int result = 0x7fffffff;

    void getMin(TreeNode *root) {
        if (root == nullptr)
            return;
        getMin(root->left);
        if (previous != nullptr && root->val - previous->val < result)
            result = root->val - previous->val;
        previous = root;
        getMin(root->right);
    }
};

