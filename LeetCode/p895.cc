class FreqStack {
 public:
  FreqStack() = default;

  void push(int val) {
    int cnt = ++val_to_cnt[val];
    if (cnt_to_val.count(cnt) == 0)
      ++max_val;
    cnt_to_val[cnt].push(val);
  }

  int pop() {
    auto &st = cnt_to_val[max_val];
    int ret = st.top();
    st.pop();
    --val_to_cnt[ret];
    if (st.empty())
      cnt_to_val.erase(max_val--);
    return ret;
  }

 private:
  unordered_map<int, int> val_to_cnt;
  unordered_map<int, stack<int>> cnt_to_val;
  int max_val = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

