class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = n * n;
        int cur = 1;
        int x = 0, y = 0;
        int mi_needs = 1;
        int sx = 0, sy = 0;
        while (cur <= count - 1) {
            x = sx;
            y = sy;
            for (; x < n - mi_needs; ++x)
                result[y][x] = cur++;
            for (; y < n - mi_needs; ++y)
                result[y][x] = cur++;
            for (; x >= mi_needs; --x)
                result[y][x] = cur++;
            for (; y >= mi_needs; --y)
                result[y][x] = cur++;
            ++mi_needs;
            ++sx;
            ++sy;
        }
        if (n & 1)
            result[n / 2][n / 2] = count;

        return result;
    }
};

