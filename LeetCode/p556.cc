class Solution {
  using ll = long long;
 public:
  int nextGreaterElement(ll n) {
    ll memo[10] = {0};
    // memo first number
    int last_bit = n % 10;
    ++memo[last_bit];
    n /= 10;
    while (n > 0) {
      int this_bit = n % 10;
      ++memo[this_bit];
      n /= 10;
      if (this_bit < last_bit) {
        // find who is first bigger than this_bit
        int add_bit;
        for (int i = this_bit + 1; i < 10; ++i) {
          if (memo[i]) {
            add_bit = i;
            break;
          }
        }
        // add bits to result
        n = n * 10 + add_bit;
        --memo[add_bit];
        for (int i = 0; i < 10; ++i) {
          while (memo[i]--)
            n = n * 10 + i;
        }
        return n > INT32_MAX ? -1 : n;
      }
      last_bit = this_bit;
    }
    return -1;
  }
};

