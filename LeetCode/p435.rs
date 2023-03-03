impl Solution {
  pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
    intervals.sort_unstable_by_key(|x| x[0]);
    let mut ret = 0;
    let mut bound = match intervals.first() {
      Some(x) => x[1],
      None => return 0,
    };
    for i in intervals.into_iter().skip(1) {
      // find conflict
      if i[0] >= bound {
        bound = i[1];
      } else {
        ret += 1;
        bound = bound.min(i[1]);
      }
    }
    ret
  }
}

