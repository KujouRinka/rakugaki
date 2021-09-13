class Solution {
    static int square (int a) {
        return a * a;
    }

public:
    int numberOfBoomerangs(const vector<vector<int>> &points) {
        int result = 0;
        for (auto &point : points) {
            unordered_map<int, int> distCnt;
            int x1 = point[0], y1 = point[1];
            for (auto &op : points) {
                int dist = square(x1 - op[0]) + square(y1 - op[1]);
                distCnt[dist]++;
            }
            for (auto &each : distCnt)
                result += each.second * (each.second - 1);
        }
        return result;
    }
};
