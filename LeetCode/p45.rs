impl Solution {
  pub fn jump(nums: Vec<i32>) -> i32 {
    let mut ret = 0;
    let mut this = 0;
    let mut next = 0;
    for i in 0..nums.len() {
      if i > this {
        ret += 1;
        this = next;
        if next >= nums.len() - 1 {
          break;
        }
      }
      next = next.max(i + nums[i] as usize);
    }
    ret
  }
}

