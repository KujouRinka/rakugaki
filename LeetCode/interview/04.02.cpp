/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }

private:
    static TreeNode *makeTree(vector<int> &nums, int lower, int upper) {
        if (lower > upper)
            return nullptr;

        int insert_ind = (lower + upper) / 2;
        auto root = new TreeNode(nums[insert_ind]);
        root->left = makeTree(nums, lower, insert_ind - 1);
        root->right = makeTree(nums, insert_ind + 1, upper);
        return root;
    }
};
