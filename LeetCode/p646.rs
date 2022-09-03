impl Solution {
  pub fn find_longest_chain(pairs: Vec<Vec<i32>>) -> i32 {
    use std::cmp::Ordering;
    use std::cmp::max;
    let mut pairs = pairs;
    pairs.sort_by(|lhs, rhs| {
      let (l0, l1) = (lhs[0], lhs[1]);
      let (r0, r1) = (rhs[0], rhs[1]);
      if l0 < r0 {
        Ordering::Less
      } else if l0 == r0 {
        l1.cmp(&r1)
      } else {
        Ordering::Greater
      }
    });
    let mut dp = Vec::new();
    dp.resize(pairs.len(), 1);
    for i in 1..pairs.len() {
      for j in 0..i {
        if pairs[j][1] < pairs[i][0] {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    dp.last().unwrap().clone()
  }
}

