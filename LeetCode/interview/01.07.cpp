class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // rotate and mirror
        auto sz = matrix.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
        int left = 0, right = sz - 1;
        while (left < right) {
            for (int i = 0; i < sz; ++i)
                swap(matrix[i][left], matrix[i][right]);
            ++left;
            --right;
        }
    }
};

