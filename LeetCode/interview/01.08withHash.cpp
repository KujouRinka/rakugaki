class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        auto sz_y = matrix.size();
        auto sz_x = matrix[0].size();
        unordered_set<int> filled_hori(sz_y);
        unordered_set<int> filled_vert(sz_x);
        for (int y = 0; y < sz_y; ++y) {
            for (int x = 0; x < sz_x; ++x) {
                if (matrix[y][x] == 0) {
                    filled_hori.insert(y);
                    filled_vert.insert(x);
                }
            }
        }
        for (auto hori: filled_hori) {
            for (int x = 0; x < sz_x; ++x)
                matrix[hori][x] = 0;
        }
        for (auto vert: filled_vert) {
            for (int y = 0; y < sz_y; ++y)
                matrix[y][vert] = 0;
        }
    }
};

