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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return {};
        m_target_sum = targetSum;
        vector<int> v;
        dfs(root, 0, v);
        return result;
    }

private:
    int m_target_sum;
    vector<vector<int>> result;

    void dfs(TreeNode *root, int this_sum, vector<int> &v) {
        int next_val = this_sum + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (next_val == m_target_sum) {
                v.push_back(root->val);
                result.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        if (root->left != nullptr)
            dfs(root->left, next_val, v);
        if (root->right != nullptr)
            dfs(root->right, next_val, v);
        v.pop_back();
    }
};

