struct Combine {
  s: String,
  tmp: Vec<String>,
  ret: Vec<Vec<String>>,
}

impl Combine {
  pub fn combine(mut self) -> Vec<Vec<String>> {
    self.backtrack(0);
    self.ret
  }

  fn backtrack(&mut self, cur_idx: usize) {
    if cur_idx == self.s.len() {
      self.ret.push(self.tmp.clone());
      return;
    }
    for i in (cur_idx + 1)..=self.s.len() {
      let this_str = &self.s[cur_idx..i];
      if Self::is_palindrome(this_str) {
        self.tmp.push(this_str.to_string());
        self.backtrack(i);
        self.tmp.pop();
      }
    }
  }

  fn is_palindrome(s: &str) -> bool {
    let mut l = 0;
    let mut r = s.len() - 1;
    while l < r {
      if s.as_bytes()[l] != s.as_bytes()[r] {
        return false;
      }
      l += 1;
      r -= 1;
    }
    true
  }
}

impl Solution {
  pub fn partition(s: String) -> Vec<Vec<String>> {
    Combine{s, tmp: Vec::new(), ret: Vec::new()}.combine()
  }
}

