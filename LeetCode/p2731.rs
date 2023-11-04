impl Solution {
  pub fn sum_distance(mut nums: Vec<i32>, s: String, d: i32) -> i32 {
    let l = s.len();
    let mut nums = nums.into_iter()
      .zip(s.as_bytes().into_iter())
      .fold(Vec::with_capacity(l), |mut acc, (n, ch)| {
        acc.push(n as i64 + if *ch == b'L' { -d } else { d } as i64);
        acc
      });
    nums.sort_unstable();
    let mut s = 0i64;
    let mut ret = 0i64;
    for (i, x) in nums.into_iter().enumerate() {
      ret = (ret + i as i64 * x - s) % (1e9 as i64 + 7);
      s += x;
    }
    ret as i32
  }
}

