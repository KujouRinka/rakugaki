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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> result;
        TreeNode *current = root;
        while (current != nullptr || !st.empty()) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                result.push_back(current->val);
                current = current->right;
            }
        }
        return result;
    }
};

