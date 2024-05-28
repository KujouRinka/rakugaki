impl Solution {
  pub fn find_peaks(mountain: Vec<i32>) -> Vec<i32> {
    mountain.windows(3)
      .into_iter()
      .fold((vec![], 1), |mut acc, w| {
        if w[1] > w[0] && w[1] > w[2] {
          acc.0.push(acc.1);
        }
        acc.1 += 1;
        acc
      }).0
  }
}

