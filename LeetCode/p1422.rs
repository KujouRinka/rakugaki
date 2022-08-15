use std::cmp::max;

impl Solution {
  pub fn max_score(s: String) -> i32 {
    let mut left_score = 0;
    let mut right_score = 0;
    s.as_bytes().iter().for_each(|ch| { if *ch == b'1' { right_score += 1; } });
    let mut max_score = 0;
    let upper = s.as_bytes().len() - 1;
    let mut i = 0;
    while i < upper {
      if s.as_bytes()[i] == b'0' {
        left_score += 1;
      } else {
        right_score -= 1;
      }
      max_score = max(max_score, left_score + right_score);
      i += 1;
    }
    max_score
  }
}

