struct Combine {
  n: i32,
  k: i32,
  tmp: Vec<i32>,
  ret: Vec<Vec<i32>>,
}

impl Combine {
  pub fn combine(mut self, k: i32, n: i32) -> Vec<Vec<i32>> {
    self.n = n;
    self.k = k;
    self.backtrack(1, 0);
    self.ret
  }

  fn backtrack(&mut self, start: i32, sum: i32) {
    if sum > self.n {
      return;
    }
    if self.tmp.len() == self.k as usize {
      if sum == self.n {
        self.ret.push(self.tmp.clone());
      }
      return;
    }
    for i in start..10 {
      self.tmp.push(i);
      self.backtrack(i + 1, sum + i);
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
    Combine{k, n , tmp: Vec::with_capacity(k as usize), ret: vec![]}.combine(k, n)
  }
}

