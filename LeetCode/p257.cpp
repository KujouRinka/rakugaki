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
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return {};
        string s(to_string(root->val));
        findPath(root, s);
        return m_result;
    }

private:
    vector<string> m_result;

    void findPath(TreeNode *root, string &s) {
        if (root->left == nullptr && root->right == nullptr) {
            m_result.push_back(s);
            return;
        }
        int sz = s.size();
        s += "->";
        int sz2 = s.size();
        if (root->left != nullptr) {
            s += to_string(root->left->val);
            findPath(root->left, s);
        }
        s.resize(sz2);
        if (root->right != nullptr) {
            s += to_string(root->right->val);
            findPath(root->right, s);
        }
        s.resize(sz);
    }
};

