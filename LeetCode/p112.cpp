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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;
        m_target_sum = targetSum;
        return dfs(root, 0);
    }

private:
    int m_target_sum;

    bool dfs(TreeNode *root, int this_sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (this_sum + root->val == m_target_sum)
                return true;
            return false;
        }
        if (root->left != nullptr && dfs(root->left, this_sum + root->val))
            return true;
        if (root->right != nullptr && dfs(root->right, this_sum + root->val))
            return true;
        return false;
    }
};

