impl Solution {
  pub fn largest_sum_of_averages(nums: Vec<i32>, k: i32) -> f64 {
    let mut dp = Vec::new();
    dp.resize(nums.len() + 1, vec![0f64; (k + 1) as usize]);
    let mut partial_sum = Vec::with_capacity(nums.len() + 1);
    partial_sum.push(0);
    let partial_sum = nums.iter().fold(partial_sum, |mut acc, x| {
      acc.push(*acc.last().unwrap() + *x);
      acc
    });
    for i in 1..=nums.len() {
      dp[i][1] = (partial_sum[i] as f64) / (i as f64);
    }
    for split in 2..=(k as usize) {
      for len in split..=nums.len() {
        for p in split - 1..len {
          dp[len][split] = dp[len][split].max(dp[p][split - 1] + (partial_sum[len] - partial_sum[p]) as f64 / (len - p) as f64);
        }
      }
    }
    dp[nums.len()][k as usize]
  }
}

