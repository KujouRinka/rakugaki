impl Solution {
  pub fn max_sum_two_no_overlap(nums: Vec<i32>, first_len: i32, second_len: i32) -> i32 {
    let mut dp = vec![vec![]; 4];
    // 0: f:; 1: s:; 2: :f; 3: :s;
    let mut f = |len: i32, idx: usize| {
      let mut cur_window = nums.iter()
        .take(len as usize)
        .sum::<i32>();
      let mut max_window = cur_window;
      dp[idx].push(max_window);
      for (i, n) in nums.iter().skip(len as usize).enumerate() {
        cur_window += n;
        cur_window -= nums[i];
        max_window = max_window.max(cur_window);
        dp[idx].push(max_window);
      }
      let mut cur_window = nums.iter()
        .rev()
        .take(len as usize)
        .sum::<i32>();
      let mut max_window = cur_window;
      dp[idx + 2].push(max_window);
      for (i, n) in nums.iter().rev().skip(len as usize).enumerate() {
        cur_window += n;
        cur_window -= nums[nums.len() - i - 1];
        max_window = max_window.max(cur_window);
        dp[idx + 2].push(max_window);
      }
      dp[idx + 2].reverse();
    };
    f(first_len, 0);
    f(second_len, 1);
    dp[0].iter().zip(dp[3].iter().skip(first_len as usize)).map(|x| x.0 + x.1).max()
      .max(
        dp[1].iter().zip(dp[2].iter().skip(second_len as usize)).map(|x| x.0 + x.1).max()
      ).unwrap()
  }
}

