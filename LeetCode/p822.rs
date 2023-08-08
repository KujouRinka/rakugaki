impl Solution {
  pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
    use std::collections::HashSet;
    let same_set = fronts.iter()
      .zip(backs.iter())
      .filter(|(f, b)| f == b)
      .map(|(f, b)| *f)
      .collect::<HashSet<_>>();
    let t = fronts.into_iter()
      .zip(backs.into_iter())
      .fold(i32::MAX, |mut acc, (f, b)| {
        if !same_set.contains(&f) {
          acc = acc.min(f);
        }
        if !same_set.contains(&b) {
          acc = acc.min(b);
        }
        acc
      });
    if t == i32::MAX { 0 } else { t }
  }
}

