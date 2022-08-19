use std::cmp::max;
use std::collections::HashMap;

impl Solution {
  pub fn max_equal_freq(nums: Vec<i32>) -> i32 {
    let mut in_i_cnt: HashMap<i32, i32> = HashMap::new();
    let mut cnt_for_i: HashMap<i32, i32> = HashMap::new();
    let mut max_cnt = 0;
    let mut ret = 0;
    for i in 0..nums.len() {
      let len = i as i32 + 1;
      let e = in_i_cnt.entry(nums[i]).or_insert(0);
      *e += 1;
      max_cnt = max(max_cnt, *e);
      *cnt_for_i.entry(*e - 1).or_insert(0) -= 1;
      *cnt_for_i.entry(*e).or_insert(0) += 1;
      if max_cnt == 1 || max_cnt * *cnt_for_i.get(&max_cnt).unwrap() + 1 == len ||
        ((max_cnt - 1) * (*cnt_for_i.get(&(max_cnt - 1)).unwrap() + 1)) + 1 == len {
        ret = len;
      }
    }
    ret
  }
}

