class DetectSquares {
public:
    DetectSquares() = default;

    void add(const vector<int> &point) {
        ++xy_map[point[0]][point[1]];
    }

    int count(const vector<int> &point) {
        int total = 0;
        for (auto &y: xy_map[point[0]]) {
            int l = y.first - point[1];
            if (y.first == point[1])
                continue;
            total += pointCount(point[0], y.first)
                     * pointCount(point[0] - l, point[1])
                     * pointCount(point[0] - l, point[1] + l);
            total += pointCount(point[0], y.first)
                     * pointCount(point[0] + l, point[1])
                     * pointCount(point[0] + l, point[1] + l);
        }
        return total;
    }

private:
    unordered_map<int, unordered_map<int, int>> xy_map;     //<x, <y, count>>

    inline int pointCount(int x, int y) {
        return xy_map[x][y];
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

