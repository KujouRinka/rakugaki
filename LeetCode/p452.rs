impl Solution {
  pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
    if points.is_empty() {
      return 0;
    }
    points.sort_unstable_by_key(|x| x[0]);
    let mut ret = 1;
    let mut bm = i32::MAX;
    for i in points.iter() {
      if i[0] > bm {
        ret += 1;
        bm = i[1];
      } else {
        bm = std::cmp::min(bm, i[1]);
      }
    }
    ret
  }
}

