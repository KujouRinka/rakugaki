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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return makeTree(nums, 0, nums.size());
    }

private:
    static TreeNode *makeTree(vector<int> &nums, int lower, int upper) {
        if (lower >= upper)
            return nullptr;

        int mid = lower + ((upper - lower) >> 1);
        TreeNode *this_node = new TreeNode(nums[mid]);
        this_node->left = makeTree(nums, lower, mid);
        this_node->right = makeTree(nums, mid + 1, upper);
        return this_node;
    }
};

