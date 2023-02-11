impl Solution {
  pub fn max_profit(prices: Vec<i32>) -> i32 {
    prices.iter()
      .zip(prices.iter().skip(1))
      .fold(0, |acc, (f, b)| {
        acc + std::cmp::max(0, *b - *f)
      })
  }
}

