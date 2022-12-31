class ExamRoom {
 public:
  ExamRoom(int n) : _hp([](auto &l, auto &r) {
    int lv = (l.second - l.first) / 2;
    int rv = (r.second - r.first) / 2;
    return lv < rv || (lv == rv && l.first > r.first);
  }), n(n) {}

  int seat() {
    int l = -1, r = -1;
    while (!_hp.empty()) {
      auto p = _hp.top();
      if (_in_seat.find(p.first) != _in_seat.end() && _in_seat.find(p.second) != _in_seat.end() && *_in_seat.upper_bound(p.first) == p.second) {
        l = p.first;
        r = p.second;
        break;
      }
      _hp.pop();
    }
    if (_hp.empty()) {
      if (_in_seat.size() == 0) {
        _in_seat.insert(0);
        return 0;
      } else if (int v = *_in_seat.begin(); v < n - v - 1) {
        _in_seat.insert(n - 1);
        _hp.push({v, n - 1});
        return n - 1;
      } else {
        _in_seat.insert(0);
        _hp.push({0, v});
        return 0;
      }
    }
    int mid = (l + r) >> 1;
    int lb = *_in_seat.begin() - 1;
    int rb = n - *prev(_in_seat.end()) - 2;
    int mb = min(mid - l, r - mid) - 1;
    if (mb > lb && mb >= rb) {
      _hp.pop();
      _in_seat.insert(mid);
      _hp.push({l, mid});
      _hp.push({mid, r});
      return mid;
    } else if (rb > lb) {
      _hp.push({*prev(_in_seat.end()), n - 1});
      _in_seat.insert(n - 1);
      return n - 1;
    } else {
      _hp.push({0, *_in_seat.begin()});
      _in_seat.insert(0);
      return 0;
    }
  }

  void leave(int p) {
    auto it = _in_seat.find(p);
    if (it != _in_seat.begin() && it != prev(_in_seat.end()))
      _hp.push({*prev(it), *next(it)});
    _in_seat.erase(p);
  }

 private:
  int n;
  set<int> _in_seat;
  priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int> &, pair<int, int> &)>> _hp;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

