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

/*
 * void postOrderVisit(TreeNode *root) {
 *     if (root == nullptr)             <- 0
 *         return;
 *     postOrderVisit(root->left);      <- 1
 *     postOrderVisit(root->right);     <- 2
 *     appendData(root->val);           <- 3
 *     return;                          <- 4
 * }
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return {};
        stack<pair<TreeNode *, int>> st;    // pair<data, PC>
        pair<TreeNode *, int> SP = {root, 0};
        vector<int> result;
        while (!(st.size() == 0 && SP.second == 4)) {
            switch (SP.second) {
                case 0:
                    if (SP.first == nullptr) {
                        SP = st.top();
                        st.pop();
                    } else {
                        ++SP.second;
                    }
                    break;
                case 1:
                    ++SP.second;
                    st.push(SP);
                    SP = {SP.first->left, 0};
                    break;
                case 2:
                    ++SP.second;
                    st.push(SP);
                    SP = {SP.first->right, 0};
                    break;
                case 3:
                    result.push_back(SP.first->val);
                    ++SP.second;
                    break;
                case 4:
                    SP = st.top();
                    st.pop();
                    break;
            }
        }
        return result;
    }
};

