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
    vector<int> findMode(TreeNode *root) {
        previous = nullptr;
        result = vector<int>();
        max_count = 0;
        this_count = 0;
        countMax(root);
        return result;
    }

private:
    TreeNode *previous = nullptr;
    vector<int> result;
    int max_count = 0;
    int this_count = 0;

    void countMax(TreeNode *root) {
        if (root == nullptr)
            return;
        countMax(root->left);
        if (previous == nullptr || previous->val == root->val)
            ++this_count;
        else
            this_count = 1;

        if (this_count > max_count) {
            max_count = this_count;
            result.clear();
        }
        if (this_count == max_count)
            result.push_back(root->val);
        previous = root;
        countMax(root->right);
    }
};

