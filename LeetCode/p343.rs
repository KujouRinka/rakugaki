impl Solution {
  pub fn integer_break(n: i32) -> i32 {
    let mut dp = vec![0i32; (n + 1) as usize];
    dp[1] = 1;
    for i in 2..=n as usize {
      for j in 1..i as usize {
        dp[i] = dp[i].max(dp[i - j] * j as i32).max(((i - j) * j) as i32);
      }
    }
    dp[n as usize]
  }
}

