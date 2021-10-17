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
    int kthSmallest(TreeNode *root, int k) {
        vector<int> t;
        dfs(root, t);
        sort(t.begin(), t.end());
        return t[k - 1];
    }

private:
    static void dfs(TreeNode *root, vector<int> &vec) {
        if (root == nullptr)
            return;
        vec.push_back(root->val);
        dfs(root->left, vec);
        dfs(root->right, vec);
    }
};
