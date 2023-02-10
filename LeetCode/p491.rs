use std::collections::HashSet;

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

  fn backtrack(&mut self, start: usize) {
    if self.tmp.len() >= 2 {
      self.ret.push(self.tmp.clone());
    }
    if start == self.nums.len() {
      return;
    }
    let mut used = HashSet::<i32>::new();
    for i in start..self.nums.len() {
      if !self.tmp.is_empty() && self.tmp.last().unwrap() > &self.nums[i] || used.contains(&self.nums[i]) {
        continue;
      }
      self.tmp.push(self.nums[i]);
      used.insert(self.nums[i]);
      self.backtrack(i + 1);
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn find_subsequences(nums: Vec<i32>) -> Vec<Vec<i32>> {
    Combine { nums, tmp: vec![], ret: vec![] }.combine()
  }
}

