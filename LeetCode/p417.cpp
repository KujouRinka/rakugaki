class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        h = &heights;
        x_sz = heights[0].size();
        y_sz = heights.size();
        P = x_sz * y_sz;
        A = x_sz * y_sz + 1;
        P_route = A_route = vector<int>(x_sz * y_sz + 2);
        for (int i = 0; i < P_route.size(); ++i)
            P_route[i] = A_route[i] = i;
        for (int i = 0; i < y_sz; ++i) {
            for (int j = 0; j < x_sz; ++j) {
                if (i == 0 || j == 0) {
                    if (!check(P_route, P, getIdx(j, i)))
                        dfs(P_route, P, j, i);
                }
                if (i == y_sz - 1 || j == x_sz - 1) {
                    if (!check(A_route, A, getIdx(j, i)))
                        dfs(A_route, A, j, i);
                }
            }
        }

        vector<vector<int>> r;
        for (int i = 0; i < y_sz; ++i) {
            for (int j = 0; j < x_sz; ++j) {
                if (check(P_route, P, getIdx(j, i)) && check(A_route, A, getIdx(j, i)))
                    r.push_back({i, j});
            }
        }
        return r;
    }

private:
    static int dirs[4][2];
    int P, A;
    int x_sz, y_sz;
    vector<int> P_route;
    vector<int> A_route;
    vector<vector<int>> *h;

    inline int getIdx(int x, int y) {
        return x + y * x_sz;
    }

    int find(vector<int> &v, int x) {
        if (v[x] != x)
            v[x] = find(v, v[x]);
        return v[x];
    }

    bool check(vector<int> &v, int x, int y) {
        return find(v, x) == find(v, y);
    }

    void un(vector<int> &v, int x, int y) {
        v[find(v, x)] = v[find(v, y)];
    }

    void dfs(vector<int> &v, int t, int x, int y) {
        un(v, t, getIdx(x, y));
        for (auto &d: dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= x_sz || ny >= y_sz)
                continue;
            if (check(v, t, getIdx(nx, ny)) || (*h)[ny][nx] < (*h)[y][x])
                continue;
            dfs(v, t, nx, ny);
        }
    }
};

int Solution::dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

