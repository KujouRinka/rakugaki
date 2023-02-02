struct Combine {
  n: i32,
  k: i32,
  tmp: Vec<i32>,
  ret: Vec<Vec<i32>>,
}

impl Combine {
  pub fn combine(mut self, n: i32, k: i32) -> Vec<Vec<i32>> {
    self.n = n;
    self.k = k;
    self.backtrack(0, 1);
    self.ret
  }

  fn backtrack(&mut self, k: i32, start: i32) {
    if k == self.k {
      self.ret.push(self.tmp.clone());
      return;
    }
    for i in start..=self.n {
      self.tmp.push(i);
      self.backtrack(k + 1, i + 1);
      self.tmp.pop();
    }
  }
}

impl Solution {
  pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
    Combine { n: 0, k: 0, tmp: Vec::with_capacity(k as usize), ret: Vec::new() }.combine(n, k)
  }
}

