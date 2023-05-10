impl Solution {
  pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
    let mut ret = 1;
    let mut acc = 1;
    loop {
      if ret >= k + 1 {
        return -1;
      }
      acc %= k;
      if acc == 0 {
        break;
      }
      acc *= 10;
      acc += 1;
      ret += 1;
    }
    ret
  }
}

