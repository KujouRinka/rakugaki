struct Combine {
  nums: Vec<i32>,
  tmp: Vec<i32>,
  ret: Vec<Vec<i32>>,
}

impl Combine {
  pub fn combine(mut self) -> Vec<Vec<i32>> {
    self.backtrack(0);
    self.ret
  }

  fn backtrack(&mut self, cur_idx: usize) {
    if cur_idx == self.nums.len() {
      self.ret.push(self.tmp.clone());
      return;
    }
    self.backtrack(cur_idx + 1);
    self.tmp.push(self.nums[cur_idx]);
    self.backtrack(cur_idx + 1);
    self.tmp.pop();
  }
}

impl Solution {
  pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
    Combine{nums, tmp: vec![], ret: vec![]}.combine()
  }
}

