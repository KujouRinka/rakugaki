class RecentCounter {
public:
    RecentCounter() = default;
    
    int ping(int t) {
        _d.push_back(t);
        return _d.end() - lower_bound(_d.begin(), _d.end(), t - 3000);
    }

private:
    vector<int> _d;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

