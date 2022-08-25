use std::cmp::Ordering;

impl Solution {
  pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
    let start = match arr.binary_search(&x) {
      Ok(v) => v,
      Err(v) => {
        if v < arr.len() && (v == 0 || (arr[v] - x) < (arr[v - 1] - x).abs()) {
          v
        } else {
          v - 1
        }
      }
    };
    assert!(start >= 0);
    let mut left: i32 = start as i32 - 1;
    let mut right: i32 = start as i32 + 1;
    let mut in_range = 1;
    // find next logic
    while in_range < k && left >= 0 && right < arr.len() as i32 {
      match Self::my_cmp(arr[left as usize], arr[right as usize], x) {
        Ordering::Less => { left -= 1; }
        Ordering::Equal => { panic!("never"); }
        Ordering::Greater => { right += 1; }
      }
      in_range += 1;
    }
    while in_range < k && left >= 0 {
      left -= 1;
      in_range += 1;
    }
    while in_range < k && right < arr.len() as i32 {
      right += 1;
      in_range += 1;
    }
    arr.into_iter().skip((left + 1) as usize).take(in_range as usize).collect()
  }

  fn my_cmp(lhs: i32, rhs: i32, x: i32) -> Ordering {
    if (lhs - x).abs() < (rhs - x).abs() || (lhs - x).abs() == (rhs - x).abs() && lhs < rhs {
      return Ordering::Less
    }
    Ordering::Greater
  }
}

