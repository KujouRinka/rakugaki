struct Combine {
  nums: Vec<i32>,
  tmp: Vec<i32>,
  used: Vec<bool>,
  ret: Vec<Vec<i32>>,
}

impl Combine {
  pub fn combine(mut self) -> Vec<Vec<i32>> {
    self.backtrack();
    self.ret
  }

  fn backtrack(&mut self) {
    if self.tmp.len() == self.nums.len() {
      self.ret.push(self.tmp.clone());
      return;
    }
    for i in 0..self.nums.len() {
      if self.used[i] {
        continue;
      }
      self.tmp.push(self.nums[i]);
      self.used[i] = true;
      self.backtrack();
      self.used[i] = false;
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
    Combine{used: vec![false; nums.len()], nums, tmp: vec![], ret: vec![]}.combine()
  }
}

