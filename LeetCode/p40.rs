struct Combine {
  candidates: Vec<i32>,
  used: Vec<bool>,
  target: i32,
  tmp: Vec<i32>,
  ret: Vec<Vec<i32>>,
}

impl Combine {
  pub fn combine(mut self) -> Vec<Vec<i32>> {
    self.candidates.sort_unstable();
    self.backtrack(0, 0);
    self.ret
  }

  fn backtrack(&mut self, mut start: i32, sum: i32) {
    if sum >= self.target {
      if sum == self.target {
        self.ret.push(self.tmp.clone());
      }
      return;
    }
    for i in (start as usize)..self.candidates.len() {
      if i > 0 && self.candidates[i] == self.candidates[i - 1] && self.used[i - 1] == false {
        continue;
      }
      self.tmp.push(self.candidates[i]);
      self.used[i] = true;
      self.backtrack((i + 1) as i32, sum + self.candidates[i]);
      self.used[i] = false;
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    Combine{used: vec![false; candidates.len()], candidates, target, tmp: Vec::new(), ret: Vec::new()}.combine()
  }
}

