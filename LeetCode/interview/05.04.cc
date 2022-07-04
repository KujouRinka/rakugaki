class Solution {
 public:
  vector<int> findClosedNumbers(int num) {
    vector<int> r(2, -1);

    // calc bigger one
    bitset<32> bs(num);
    int last_bit = bs[0];
    int one_memo = last_bit == 0 ? 0 : 1;
    bool ok = false;
    for (int i = 1; i < 32; ++i) {
      int this_bit = bs[i];
      if (this_bit)
        ++one_memo;
      if (this_bit == 0 && last_bit == 1) {
        ok = true;
        // do work
        int j = 0;
        bs[i] = true;
        --one_memo;
        for (; one_memo > 0; --one_memo, ++j)
          bs[j] = true;
        for (; j < i; ++j)
          bs[j] = false;
        break;
      }
      last_bit = this_bit;
    }
    if (ok)
      r[0] = bs.to_ulong() > INT32_MAX ? -1 : bs.to_ulong();

    // calc smaller one
    ok = false;
    bs = num;
    last_bit = bs[0];
    one_memo = last_bit == 0 ? 0 : 1;
    for (int i = 1; i < 32; ++i) {
      int this_bit = bs[i];
      if (this_bit)
        ++one_memo;
      if (this_bit == 1 && last_bit == 0) {
        ok = true;
        bs[i--] = false;
        while (one_memo--)
          bs[i--] = true;
        for (; i >= 0; --i)
          bs[i] = false;
        break;
      }
      last_bit = this_bit;
    }
    if (ok)
      r[1] = bs.to_ulong();
    return r;
  }
};

