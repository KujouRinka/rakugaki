class MyCalendar {
 public:
  MyCalendar() = default;

  bool book(int start, int end) {
    if (start >= end)
      return false;
    auto low = _calendar.lower_bound(start);
    if (low->first == start || (low != _calendar.begin() && prev(low)->second > start))
      return false;
    auto high = _calendar.lower_bound(end);
    if (high != low)
      return false;
    _calendar.insert(low, {start, end});
    return true;
  }

 private:
  map<int, int> _calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
