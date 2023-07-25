use std::collections::BinaryHeap;
use std::cmp::Ordering;

struct F64(f64);

impl PartialEq for F64 {
  fn eq(&self, other: &Self) -> bool {
    (self.0 - other.0).abs() < 1e-6
  }
}

impl Eq for F64 {}

impl PartialOrd for F64 {
  fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
    (self.0 - other.0).partial_cmp(&0.0)
  }
}

impl Ord for F64 {
  fn cmp(&self, other: &Self) -> Ordering {
    (self.0 - other.0).partial_cmp(&0.0).unwrap()
  }
}

impl Solution {
  pub fn halve_array(nums: Vec<i32>) -> i32 {
    let mut oper = F64(nums.iter().map(|x| (*x) as f64).sum::<f64>() / 2.0);
    let mut nums: BinaryHeap<_> = nums.into_iter()
      .map(|x| F64(x as f64))
      .collect();
    let mut cnt = 0;
    while oper > F64(0.0) {
      let v = nums.pop().unwrap();
      let v = v.0 / 2.0;
      oper = F64(oper.0 - v);
      cnt += 1;
      nums.push(F64(v));
    }
    cnt
  }
}

