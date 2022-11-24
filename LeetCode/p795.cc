class Solution {
 public:
  int numSubarrayBoundedMax(const vector<int> &nums, int left, int right) {
    vector<int> lb(nums.size());
    vector<int> rb(nums.size());
    stack<int> st;
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (!st.empty() && nums[st.top()] < nums[i]) {
        int tp = st.top();
        st.pop();
        lb[i] = i - tp + lb[tp];
      }
      st.push(i);
    }
    stack<int> es;
    st.swap(es);
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!st.empty() && nums[st.top()] <= nums[i]) {
        int tp = st.top();
        st.pop();
        rb[i] = tp - i + rb[tp];
      }
      st.push(i);
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= left && nums[i] <= right) {
        ret += (lb[i] + 1) * (rb[i] + 1);
      }
    }
    return ret;
  }
};

