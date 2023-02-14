impl Solution {
  pub fn candy(ratings: Vec<i32>) -> i32 {
    let mut vl = vec![1; ratings.len()];
    let mut vr = vec![1; ratings.len()];
    for i in 1..ratings.len() {
      if ratings[i] > ratings[i - 1] {
        vl[i] = vl[i - 1] + 1;
      }
    }
    for i in (0..ratings.len() - 1).rev() {
      if ratings[i] > ratings[i + 1] {
        vr[i] = vr[i + 1] + 1;
      }
    }
    vl.into_iter()
      .zip(vr.into_iter())
      .map(|(l, r)| {
        std::cmp::max(l, r)
      })
      .fold(0, |acc, x| {
        acc + x
      })
  }
}

