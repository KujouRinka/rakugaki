class Solution {
    static int dirs[5];

public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        auto sz_big = heightMap.size();
        auto sz_small = heightMap[0].size();
        if (sz_big <= 2 || sz_small <= 2)
            return 0;
        int volume = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> height_heap;
        vector<vector<bool>> visited(sz_big, vector<bool>(sz_small, false));
        // init outline
        for (int i = 0; i < sz_small; ++i) {
            height_heap.push(make_tuple(heightMap[0][i], 0, i));
            height_heap.push(make_tuple(heightMap[sz_big - 1][i], sz_big - 1, i));
            visited[0][i] = visited[sz_big - 1][i] = true;
        }
        for (int i = 1; i < sz_big - 1; ++i) {
            height_heap.push(make_tuple(heightMap[i][0], i, 0));
            height_heap.push(make_tuple(heightMap[i][sz_small - 1], i, sz_small - 1));
            visited[i][0] = visited[i][sz_small - 1] = true;
        }
        while (!height_heap.empty()) {
            auto[height, x, y] = height_heap.top();
            height_heap.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx >= 0 && ny >= 0 && nx < sz_big && ny < sz_small && !visited[nx][ny]) {
                    int &h = heightMap[nx][ny];
                    if (height > h) {
                        volume += height - h;
                        h = height;
                    }
                    height_heap.push(make_tuple(h, nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        return volume;
    }
};

int Solution::dirs[] = {-1, 0, 1, 0, -1};
