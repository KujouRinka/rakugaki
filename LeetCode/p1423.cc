class Solution {
 public:
  int maxScore(vector<int> &cardPoints, int k) {
    int f = 0, b = cardPoints.size() - 1;
    int sum = 0;
    while (f < k) {
      sum += cardPoints[f++];
    }

    int ret = sum;
    while (f > 0) {
      sum -= cardPoints[--f];
      sum += cardPoints[b--];
      ret = max(ret, sum);
    }
    return ret;
  }
};

