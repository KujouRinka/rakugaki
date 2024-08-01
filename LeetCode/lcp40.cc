class Solution {
 public:
  int maxmiumScore(vector<int> &cards, int cnt) {
    sort(cards.begin(), cards.end(), greater<>());

    int memo = -1;
    int m2 = -1;
    int ret = 0;

    for (int i = 0; i < cnt; ++i) {
      if (cards[i] & 1) {
        if (memo == -1) {
          memo = i;
        } else {
          memo = -1;
        }
      } else {
        m2 = i;
      }
      ret += cards[i];
    }

    if (!(ret & 1)) {
      return ret;
    }

    int v1 = -1;
    int v2 = -1;
#define likely(x) (__builtin_expect(!!(x), 0))
    for (int i = cnt; i < cards.size(); ++i) {
      if (likely(v1 == -1) && !(cards[i] & 1)) {
        v1 = ret - cards[memo] + cards[i];
      }
      if (m2 != -1 && likely(v2 == -1) && (cards[i] & 1)) {
        v2 = ret - cards[m2] + cards[i];
      }
    }
    return max(max(v1, v2), 0);
  }
};

