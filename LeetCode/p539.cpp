class Solution {
public:
    int findMinDifference(const vector<string> &timePoints) {
        if (timePoints.size() > 1440)
            return 0;
        array<int, 1440> time_map{};
        for (auto &t: timePoints)
            if (++time_map[timeToInt(t)] > 1)
                return 0;

        int min_delta = 0x7fffffff;
        int cur_idx = 0;
        while (time_map[cur_idx] == 0)
            ++cur_idx;
        int first_idx = cur_idx;

        int next_idx = cur_idx;
        while (cur_idx <= next_idx) {
            cur_idx = next_idx;
            for (int i = cur_idx + 1; i < 1440; ++i)
                if (time_map[i] != 0) {
                    next_idx = i;
                    break;
                }
            if (next_idx == cur_idx)
                next_idx = first_idx;
            min_delta = min(min_delta, (next_idx - cur_idx + 1440) % 1440);
        }

        return min_delta;
    }

private:
    static inline int timeToInt(const string &time) {
        const char *p = time.c_str();
        int first, second;
        from_chars(p, p + 2, first);
        from_chars(p + 3, p + 5, second);
        return first * 60 + second;
    }
};

