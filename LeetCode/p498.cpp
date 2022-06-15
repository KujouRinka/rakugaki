class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int y_sz = mat.size();
        if (y_sz == 0)
            return {};
        int x_sz = mat[0].size();
        if (x_sz == 0)
            return {};
        vector<int> r;
        bool dir = false;
        r.reserve(x_sz * y_sz);
        int idx = x_sz + y_sz - 1;
        for (int xi = 0; xi < idx; ++xi) {
            if (dir) {
                int x = xi, y = 0;
                while (x >= 0 && y < y_sz) {
                    if (x < x_sz)
                        r.push_back(mat[y][x]);
                    --x; ++y;
                }
            } else {
                int x = 0, y = xi;
                while (x < x_sz && y >= 0) {
                    if (y < y_sz)
                        r.push_back(mat[y][x]);
                    ++x; --y;
                }
            }
            dir = !dir;
        }
        return r;
    }
};

