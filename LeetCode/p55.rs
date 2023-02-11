impl Solution {
  pub fn can_jump(nums: Vec<i32>) -> bool {
    let mut bounder = 0;
    for i in 0..nums.len() {
      if i > bounder {
        return false;
      }
      bounder = bounder.max(i + nums[i] as usize);
    }
    true
  }
}

