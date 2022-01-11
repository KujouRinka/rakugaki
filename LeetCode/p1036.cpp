#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

namespace std {
    template<>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int> &p) const noexcept {
            return hash<long long>()
                    (static_cast<long long>(p.first) << 20 | p.second);
        }
    };
}

class Solution {
    static const int dir[4][2];

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
        max_search = blocked.size() * (blocked.size() - 1) / 2 + blocked.size();
        for (auto &vec: blocked)
            block_map.insert({vec[0], vec[1]});
        t = vector<int>{target[0], target[1]};
        bool b1 = dfs(source[0], source[1]);
        visited.clear();
        t[0] = source[0];
        t[1] = source[1];
        return b1 && dfs(target[0], target[1]);
    }

private:
    int max_search;
    vector<int> t;
    unordered_set<pair<int, int>> block_map;
    unordered_set<pair<int, int>> visited;

    bool dfs(int sx, int sy) {
        if (visited.size() == max_search || (sx == t[0] && sy == t[1]))
            return true;
        for (auto &i: dir) {
            int nx = sx + i[0];
            int ny = sy + i[1];
            if (!isValid(nx, ny))
                continue;
            if (block_map.count({nx, ny}))
                continue;
            if (visited.count({nx, ny}))
                continue;
            visited.insert({nx, ny});
            if (dfs(nx, ny))
                return true;
        }
        return false;
    }

    static inline bool isValid(int x, int y) {
        return x >= 0 && x < 1e6 && y >= 0 && y < 1e6;
    }
};

const int Solution::dir[4][2] = {{0,  -1},
                                 {0,  1},
                                 {-1, 0},
                                 {1,  0}};

