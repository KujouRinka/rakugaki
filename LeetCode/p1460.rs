use std::collections::HashMap;

impl Solution {
  pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
    if target.len() != arr.len() {
      return false;
    }
    let mut hash: HashMap<i32, i32> = HashMap::new();
    for (i, j) in target.into_iter().zip(arr.into_iter()) {
      *hash.entry(i).or_insert(0) += 1;
      *hash.entry(j).or_insert(0) -= 1;
    }
    for v in hash.values() {
      if *v != 0 {
        return false;
      }
    }
    true
  }
}

