impl Solution {
  pub fn last_stone_weight_ii(stones: Vec<i32>) -> i32 {
    let acc_cp = stones.iter().sum::<i32>() as usize;
    let acc = acc_cp >> 1;
    let mut dp = vec![vec![false; acc + 1]; stones.len()];
    let mut memo = 0;
    dp[0][0] = true;
    match dp[0].get_mut(stones[0] as usize) {
      Some(mt) => *mt = true,
      None => {}
    }
    for i in 1..stones.len() {
      for j in 0..=acc as usize {
        if j >= stones[i] as usize {
          dp[i][j] = dp[i - 1][j - stones[i] as usize];
        }
        dp[i][j] = dp[i][j] || dp[i - 1][j];
        if dp[i][j] {
          memo = memo.max(j);
        }
      }
    }
    acc_cp as i32 - memo as i32 * 2
  }
}

