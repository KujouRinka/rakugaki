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
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        _target = target;
        dfs(root, 0);
        return _result;
    }

private:
    int _target;
    vector<int> _path;
    vector<vector<int>> _result;

    void dfs(TreeNode *root, int cur) {
        if (root == nullptr)
            return;
        cur += root->val;
        _path.push_back(root->val);
        if (cur == _target && root->left == nullptr && root->right == nullptr)
            _result.emplace_back(_path);
        dfs(root->left, cur);
        dfs(root->right, cur);
        _path.pop_back();
    }
};

