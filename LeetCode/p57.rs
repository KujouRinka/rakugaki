impl Solution {
  pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
    if intervals.is_empty() {
      return vec![new_interval];
    }

    let (mut left, mut right) = (new_interval[0], new_interval[1]);
    let mut p = false;
    let mut ret = Vec::new();

    for (l, r) in intervals.into_iter().map(|v| (v[0], v[1])) {
      if l > right {
        if !p {
          ret.push(vec![left, right]);
          p = true;
        }
        ret.push(vec![l, r]);
      } else if r < left {
        ret.push(vec![l, r]);
      } else {
        left = left.min(l);
        right = right.max(r);
      }
    }
    if !p {
      ret.push(vec![left, right]);
    }

    ret
  }
}

