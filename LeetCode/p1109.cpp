class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> d(n);
        for (auto &i : bookings) {
            d[i[0] - 1] += i[2];
            if (i[1] < n)
                d[i[1]] -= i[2];
        }
        partial_sum(d.begin(), d.end(), d.begin());
        return d;
    }
};
