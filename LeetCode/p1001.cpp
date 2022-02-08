class Solution {
public:
    vector<int> gridIllumination(
            int n, const vector<vector<int>> &lamps,
            const vector<vector<int>> &queries
    ) {
        grid_size = n;
        vector<int> result;
        result.reserve(queries.size());

        for (auto &lamp: lamps) {
            if (lamp_set.count(lampToKey(lamp[0], lamp[1])) == 0) {
                addLamp(lamp[0], lamp[1]);
            }
        }

        for (auto &query: queries) {
            int x = query[0], y = query[1];
            if (x_light[x] || y_light[y] || left_light[y - x] || right_light[x + y])
                result.push_back(1);
            else
                result.push_back(0);
            removeLampAround(x, y);
        }
        return result;
    }

private:
    int grid_size;
    unordered_map<int, int> x_light;
    unordered_map<int, int> y_light;
    unordered_map<int, int> left_light;
    unordered_map<int, int> right_light;
    unordered_set<long long> lamp_set;

    void addLamp(int x, int y) {
        ++x_light[x];
        ++y_light[y];
        ++left_light[y - x];
        ++right_light[x + y];
        lamp_set.insert(lampToKey(x, y));
    }

    void removeLampAround(int x, int y) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i, ny = y + j;
                if (lamp_set.count(lampToKey(nx, ny)) == 0)
                    continue;
                if (isValid(nx, ny))
                    removeLamp(nx, ny);
            }
        }
    }

    void removeLamp(int x, int y) {
        --x_light[x];
        --y_light[y];
        --left_light[y - x];
        --right_light[x + y];
        lamp_set.erase(lampToKey(x, y));
    }

    inline long long lampToKey(long long x, long long y) const {
        return y * grid_size + x;
    }

    inline bool isValid(int x, int y) {
        return x >= 0 && x < grid_size && y >= 0 && y < grid_size;
    }
};

