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
        int x = 0, y = 0;
        while (true) {
            if (!dir) {
                while (x < x_sz && y >= 0) {
                    r.push_back(mat[y][x]);
                    ++x, --y;
                }
                if (x < x_sz && y + 1 >= 0)
                    ++y;
                else
                    --x, y += 2;
            } else {
                while (x >= 0 && y < y_sz) {
                    r.push_back(mat[y][x]);
                    --x, ++y;
                }
                if (x + 1 >= 0 && y < y_sz)
                    ++x;
                else
                    x += 2, --y;
            }
            if (x < 0 || x >= x_sz || y < 0 || y >= y_sz)
                break;
            dir = !dir;
        }
        return r;
    }
};

