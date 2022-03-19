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
    string tree2str(TreeNode* root) {
        dfs(root);
        return _result;
    }

private:
    string _result;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        _result.append(to_string(root->val));
        if (!root->left && !root->right)
            return;
        _result.push_back('(');
        dfs(root->left);
        _result.push_back(')');
        _result.push_back('(');
        dfs(root->right);
        if (_result.back() == '(')
            _result.pop_back();
        else
            _result.push_back(')');
    }
};

