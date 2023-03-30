impl Solution {
  pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
    let mut s = points.into_iter()
      .map(|x| unsafe { *x.get_unchecked(0) })
      .collect::<Vec<_>>();
    s.sort_unstable();
    s.windows(2)
      .fold(0, |mut acc, x| {
        unsafe { acc.max(*x.get_unchecked(1) - *x.get_unchecked(0)) }
      })
  }
}

