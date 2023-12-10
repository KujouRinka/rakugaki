class Solution {
 public:
  long long pickGifts(vector<int> &gifts, int k) {
    long long acc = accumulate(gifts.begin(), gifts.end(), 0LL);
    priority_queue<int> hp(gifts.begin(), gifts.end());
    while (k--) {
      auto n = hp.top();
      hp.pop();
      long long m = sqrt(n);
      acc -= n - m;
      hp.push(m);
    }
    return acc;
  }
};

