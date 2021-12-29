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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> result;
        st.push(root);
        while (!st.empty()) {
            TreeNode *this_node = st.top();
            st.pop();
            if (this_node != nullptr) {
                result.push_back(this_node->val);
                st.push(this_node->left);
                st.push(this_node->right);
            }
        }
        return {result.rbegin(), result.rend()};
    }
};

