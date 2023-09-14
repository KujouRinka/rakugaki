impl Solution {
  pub fn max_dist_to_closest(mut seats: Vec<i32>) -> i32 {
    seats.push(1);
    let (mut prev, mut cur) = (-1, -1);
    let mut ret = 0;
    for (i, &s) in seats.iter().enumerate() {
      if s == 0 {
        continue;
      }
      prev = cur;
      cur = i as i32;
      ret = ret.max((cur - prev) / 2);
    }
    if seats[0] == 0 {
      let mut j = 0;
      for &i in seats.iter().skip(1) {
        j += 1;
        if i == 1 {
          break;
        }
      }
      ret = ret.max(j);
    }
    seats.pop();
    if seats.last().unwrap() == &0 {
      let mut j = 0;
      for &i in seats.iter().rev().skip(1) {
        j += 1;
        if i == 1 {
          break;
        }
      }
      ret = ret.max(j);
    }
    ret
  }
}

