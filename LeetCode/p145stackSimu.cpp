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
        pair<TreeNode *, int> FP = {root, 0};
        vector<int> result;
        while (!(st.size() == 0 && FP.second == 4)) {
            switch (FP.second) {
                case 0:
                    if (FP.first == nullptr) {
                        FP = st.top();
                        st.pop();
                    } else {
                        ++FP.second;
                    }
                    break;
                case 1:
                    ++FP.second;
                    st.push(FP);
                    FP = {FP.first->left, 0};
                    break;
                case 2:
                    ++FP.second;
                    st.push(FP);
                    FP = {FP.first->right, 0};
                    break;
                case 3:
                    result.push_back(FP.first->val);
                    ++FP.second;
                    break;
                case 4:
                    FP = st.top();
                    st.pop();
                    break;
            }
        }
        return result;
    }
};

