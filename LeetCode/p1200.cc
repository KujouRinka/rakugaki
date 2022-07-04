class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    if (arr.size() < 2)
      return {};
    sort(arr.begin(), arr.end());
    int min_diff = arr.back() - arr.front();
    vector<vector<int>> r;
    for (int i = 1; i < arr.size(); ++i) {
      if (int diff = arr[i] - arr[i - 1]; diff < min_diff) {
        min_diff = diff;
        r.clear();
        r.push_back({arr[i - 1], arr[i]});
      } else if (diff == min_diff) {
        r.push_back({arr[i - 1], arr[i]});
      }
    }
    return r;
  }
};

