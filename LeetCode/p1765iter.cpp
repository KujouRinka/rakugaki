class Solution {
public:
    vector<vector<int>> highestPeak(const vector<vector<int>> &isWater) {
        m_y_size = isWater.size();
        m_x_size = isWater[0].size();
        result = vector<vector<int>>(m_y_size, vector<int>(m_x_size, -1));
        queue<pair<int, int>> water;
        for (int y = 0; y < m_y_size; ++y) {
            for (int x = 0; x < m_x_size; ++x)
                if (isWater[y][x] == 1) {
                    water.push({x, y});
                    result[y][x] = 0;
                }
        }
        bfs(isWater, water);
        return result;
    }

private:
    int m_x_size;
    int m_y_size;
    static int dirs[4][2];
    vector<vector<int>> result;

    void bfs(const vector<vector<int>> &isWater, queue<pair<int, int>> &next) {
        while (!next.empty()) {
            for (int i = next.size(); i > 0; --i) {
                auto[x, y] = next.front();
                next.pop();
                int this_height = result[y][x];
                for (auto &dir: dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (isValid(nx, ny) && result[ny][nx] == -1) {
                        if (isWater[ny][nx] == 1) {
                            result[ny][nx] = 0;
                        } else {
                            result[ny][nx] = this_height + 1;
                            next.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    inline bool isValid(int x, int y) {
        return x >= 0 && x < m_x_size && y >= 0 && y < m_y_size;
    }
};

int Solution::dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

