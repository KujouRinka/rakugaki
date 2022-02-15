class Solution {
public:
    vector<int> luckyNumbers(const vector<vector<int>> &matrix) {
        vector<int> x_max(matrix.size(), 0x7fffffff);
        vector<int> y_max(matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < x_max[i])
                    x_max[i] = matrix[i][j];
                if (matrix[i][j] > y_max[j])
                    y_max[j] = matrix[i][j];
            }
        }

        vector<int> result;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == x_max[i] && matrix[i][j] == y_max[j])
                    result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};

