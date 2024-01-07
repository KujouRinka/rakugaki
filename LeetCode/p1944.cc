class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    stack<int> st;
    vector<int> ret(heights.size(), 0);
    for (int i = heights.size() - 1; i >= 0; --i) {
      int r = 0;
      while (!st.empty() && heights[st.top()] < heights[i]) {
        st.pop();
        ++r;
      }
      if (!st.empty()) {
        ++r;
      }
      ret[i] = r;
      st.push(i);
    }
    return ret;
  }
};

