impl Solution {
  pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
    use std::collections::HashSet;
    let jewels: HashSet<_> = jewels.as_bytes().into_iter().collect();
    stones.as_bytes()
      .into_iter()
      .filter(|x| {
        jewels.contains(x)
      })
      .count() as i32
  }
}

