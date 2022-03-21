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
    bool findTarget(TreeNode* root, int k) {
        _k = k;
        return dfs(root);
    }

private:
    int _k;
    unordered_set<int> _num_set;
    
    bool dfs(TreeNode *node) {
        if (node == nullptr)
            return false;
        if (_num_set.count(_k - node->val))
            return true;
        _num_set.insert(node->val);
        return dfs(node->left) || dfs(node->right);
    }
};

