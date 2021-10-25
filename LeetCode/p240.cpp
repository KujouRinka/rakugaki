class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = matrix[0].size();
        auto sz_x = matrix.size();
        while (true) {
            if (x > sz_x || y < 0)
                return false;
            if (matrix[x][y] > target)
                --y;
            else if (matrix[x][y] < target)
                ++x;
            else
                return true;
        }
    }
};
