class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        _target = sum;
        _r = 0;
        _partial_sum_map[0] = 1;
        search(root, 0);
        return _r;
    }

private:
    int _r;
    int _target;
    unordered_map<int, int> _partial_sum_map;   // <sum, times>

    void search(TreeNode *root, int prev_sum) {
        if (root == nullptr)
            return;
        int this_sum = prev_sum + root->val;
        _r += _partial_sum_map[this_sum - _target];
        ++_partial_sum_map[this_sum];
        search(root->left, this_sum);
        search(root->right, this_sum);
        --_partial_sum_map[this_sum];
    }
};

