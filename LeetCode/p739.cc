class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    vector<int> ret(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
      while (!st.empty()) {
        auto top = st.top();
        if (temperatures[i] >= temperatures[top]) {
          st.pop();
        } else {
          ret[i] = top - i;
          break;
        }
      }
      st.push(i);
    }
    return ret;
  }
};

