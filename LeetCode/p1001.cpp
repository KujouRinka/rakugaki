class Solution {
public:
    vector<int> gridIllumination(
            int n, const vector<vector<int>> &lamps,
            const vector<vector<int>> &queries
    ) {
        grid_sz = n;
        vector<vector<int>> brightness(n, vector<int>(n, 0));
        vector<int> result;
        result.reserve(queries.size());
        set<pair<int, int>> lamp_set;

        for (auto &lamp: lamps) {
            if (lamp_set.count({lamp[0], lamp[1]}) == 0) {
                addLight(brightness, lamp[0], lamp[1]);
                lamp_set.insert({lamp[0], lamp[1]});
            }
        }
        for (auto &query: queries) {
            if (brightness[query[1]][query[0]] > 0)
                result.push_back(1);
            else
                result.push_back(0);
            removeLightAround(brightness, lamp_set, query[0], query[1]);
        }

        return result;
    }

private:
    int grid_sz;

    void addLight(vector<vector<int>> &brightness, int x, int y) {
        lightOper(brightness, x, y, 1);
    }

    void removeLightAround(vector<vector<int>> &brightness, set<pair<int, int>> &lamp_set, int x, int y) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i, ny = y + j;
                if (!isValid(nx, ny))
                    continue;
                if (lamp_set.count({nx, ny})) {
                    lightOper(brightness, nx, ny, -1);
                    lamp_set.erase({nx, ny});
                }
            }
        }
    }

    void lightOper(vector<vector<int>> &brightness, int x, int y, int oper) {
        for (int i = 0; i < grid_sz; ++i) {
            if (i != y)
                brightness[i][x] += add(brightness, x, i, oper);
            if (i != x)
                brightness[y][i] += add(brightness, i, y, oper);
            int left_x = i - (y - x);
            int left_y = i;
            int right_x = x + y - i;
            int right_y = i;
            if (isValid(left_x, left_y) && (left_x != x || left_y != y))
                brightness[left_y][left_x] += add(brightness, left_x, left_y, oper);
            if (isValid(right_x, right_y) && (right_x != x || right_y != y))
                brightness[right_y][right_x] += add(brightness, right_x, right_y, oper);
        }
        brightness[y][x] += add(brightness, x, y, oper);
    }

    static inline int add(vector<vector<int>> &brightness, int x, int y, int oper) {
        if (oper >= 0)
            return oper;
        return brightness[y][x] - oper > 0 ? oper : 0;
    }

    inline bool isValid(int x, int y) {
        return x >= 0 && x < grid_sz && y >= 0 && y < grid_sz;
    }
};

