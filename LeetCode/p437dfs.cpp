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
private:
    int count = 0;
    int target = 0;
    void dfsTree(TreeNode *root) {
        if (root == nullptr)
            return;

        dfsNode(root, 0);
        dfsTree(root->left);
        dfsTree(root->right);
    }

    void dfsNode(TreeNode *root, int t) {
        if (root == nullptr)
            return;
        int tt = t + root->val;
        if (tt == target)
            ++count;

        dfsNode(root->left, tt);
        dfsNode(root->right, tt);
    }
public:
    int pathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        dfsTree(root);
        return count;
    }
};
