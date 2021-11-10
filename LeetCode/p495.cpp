class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int bounder = timeSeries.size() - 1;
        int time_sum = 0;
        for (int i = 0; i < bounder; ++i)
            time_sum += min(duration, timeSeries[i + 1] - timeSeries[i]);
        time_sum += duration;
        return time_sum;
    }
};
