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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> t;
        while (!q.empty()) {
            t.clear();
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode *this_node = q.front();
                q.pop();
                if (this_node != nullptr) {
                    t.push_back(this_node->val);
                    q.push(this_node->left);
                    q.push(this_node->right);
                }
            }
            if (!t.empty())
                result.push_back(t);
        }

        return result;
    }
};

