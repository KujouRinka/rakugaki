class Solution {
public:
  int maxDistance(vector<vector<int> > &arrays) {
    if (arrays.size() < 2) {
      return -1;
    }
    max_hp[0] = {arrays[0].back(), 0};
    max_hp[1] = {arrays[1].back(), 1};
    min_hp[0] = {arrays[0].front(), 0};
    min_hp[1] = {arrays[1].front(), 1};
    if (max_hp[0].first < max_hp[1].first) {
      swap(max_hp[0], max_hp[1]);
    }
    if (min_hp[0].first > min_hp[1].first) {
      swap(min_hp[0], min_hp[1]);
    }
    for (auto it = arrays.begin() + 2; it != arrays.end(); it++) {
      in_max({it->back(), it - arrays.begin()});
      in_min({it->front(), it - arrays.begin()});
    }

    return max_hp[0].second != min_hp[0].second ?
      max_hp[0].first - min_hp[0].first :
      max(max_hp[0].first - min_hp[1].first, max_hp[1].first - min_hp[0].first);
  }

private:
  int current_max_dist = 0;
  pair<int, int> max_hp[2];
  pair<int, int> min_hp[2];

  void in_max(pair<int, int> v) {
    if (v.first > max_hp[1].first) {
      max_hp[1] = v;
    }
    if (v.first > max_hp[0].first) {
      swap(max_hp[0], max_hp[1]);
    }
  }

  void in_min(pair<int, int> v) {
    if (v.first < min_hp[1].first) {
      min_hp[1] = v;
    }
    if (v.first < min_hp[0].first) {
      swap(min_hp[0], min_hp[1]);
    }
  }
};
