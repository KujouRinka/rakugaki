impl Solution {
  pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
    nums.into_iter()
      .filter(|x| x & 1 == 0)
      .fold(std::collections::HashMap::new(), |mut acc, x| {
        *acc.entry(x).or_insert(0) += 1;
        acc
      })
      .into_iter()
      .fold((-1, -1), |mut acc, (k, v)| {
        if v > acc.1 {
          acc.0 = k;
          acc.1 = v;
        } else if v == acc.1 && k < acc.0 {
          acc.0 = k;
        }
        acc
      }).0
  }
}

