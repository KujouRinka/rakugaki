class Solution {
 public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    if (asteroids.size() <= 1)
      return {};
    list<int> lst(asteroids.begin(), asteroids.end());
    auto p = lst.begin();
    while (p != prev(lst.end())) {
      while (p != prev(lst.end()) && !(*p > 0 && *next(p) < 0))
        ++p;
      if (p != prev(lst.end())) {
        auto del_it = lst.end();
        if (*p < abs(*next(p)))
          del_it = p;
        else if (*p > abs(*next(p)))
          del_it = next(p);

        if (del_it == lst.end()) {
          lst.erase(next(p));
          del_it = lst.erase(p);
        } else {
          del_it = lst.erase(del_it);
        }
        p = del_it == lst.begin() ? del_it : prev(del_it);
      }
    }
    return {lst.begin(), lst.end()};
  }
};

