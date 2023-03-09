impl Solution {
  pub fn num_trees(n: i32) -> i32 {
    let mut dp = vec![0; (n + 1) as usize];
    dp[1] = 1;
    for i in 2..=n as usize {
      for j in 0..i {
        dp[i] += std::cmp::max(1, dp[j]) * std::cmp::max(1, dp[i - j - 1]);
      }
    }
    dp[n as usize]
  }
}

