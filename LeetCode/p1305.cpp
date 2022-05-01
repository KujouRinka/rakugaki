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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        dfs(v1, root1);
        dfs(v2, root2);
        vector<int> r;
        int i1 = 0, i2 = 0, sz1 = v1.size(), sz2 = v2.size();
        while (i1 < sz1 && i2 < sz2) {
            if (v1[i1] < v2[i2])
                r.push_back(v1[i1++]);
            else
                r.push_back(v2[i2++]);
        }
        while (i1 < sz1)
            r.push_back(v1[i1++]);
        while (i2 < sz2)
            r.push_back(v2[i2++]);
        return r;
    }

private:
    void dfs(vector<int> &v, TreeNode *node) {
        if (node == nullptr)
            return;
        dfs(v, node->left);
        v.push_back(node->val);
        dfs(v, node->right);
    }
};

