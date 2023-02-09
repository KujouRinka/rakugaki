impl Combine {
  pub fn combine(mut self) -> Vec<Vec<i32>> {
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
      self.tmp.push(self.candidates[i]);
      self.backtrack(start, sum + self.candidates[i]);
      start += 1;
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    Combine{candidates, target, tmp: Vec::new(), ret: Vec::new()}.combine()
  }
}

