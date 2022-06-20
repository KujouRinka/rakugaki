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
    vector<int> findFrequentTreeSum(TreeNode *root) {
        if (root == nullptr)
            return {};
        treeSum(root);
        vector<int> result;
        int max_count = 0;
        for_each(_sum_count.begin(), _sum_count.end(), [&max_count, &result](auto &it) {
            if (it.second == max_count) {
                result.push_back(it.first);
            } else if (it.second > max_count) {
                max_count = it.second;
                vector<int>{it.first}.swap(result);
            }
        });
        return result;
    }

private:
    unordered_map<int, int> _sum_count;

    int treeSum(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = treeSum(root->left);
        int right = treeSum(root->right);
        int ret = left + right + root->val;
        ++_sum_count[ret];
        return ret;
    }
};

