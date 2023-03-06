impl Solution {
  pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    intervals.sort_unstable_by_key(|x| x[0]);
    intervals.into_iter()
      .fold(Vec::new(), |mut acc, x| {
        if let Some(mut last) = acc.last_mut() {
          if last[1] >= x[0] {
            last[1] = last[1].max(x[1]);
            return acc;
          }
        }
        acc.push(x);
        acc
      })
  }
}

