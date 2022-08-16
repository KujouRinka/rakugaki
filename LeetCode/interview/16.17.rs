use std::cmp::max;

impl Solution {
  pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    let mut max_v = nums[0];
    nums.iter().fold(0, |sum, x| {
      let mut ret = max(sum, 0);
      ret += *x;
      max_v = max(max_v, ret);
      ret
    });
    max_v
  }
}

