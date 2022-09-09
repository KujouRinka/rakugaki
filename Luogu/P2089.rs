fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let arg = arg.trim().parse::<i32>().unwrap();
  let mut s = Solution {
    target: arg,
    ret: Vec::new(),
  };
  s.run();
  let ret = s.result();
  println!("{}", ret.len());
  ret.iter()
    .for_each(|v| {
      v.iter().for_each(|x| print!("{} ", x));
      println!();
    });
}

struct Solution {
  target: i32,
  ret: Vec<Vec<i32>>,
}

impl Solution {
  fn run(&mut self) {
    self.f(0, 0, Vec::new());
  }

  fn f(&mut self, idx: i32, sum: i32, mut cur: Vec<i32>) -> Vec<i32> {
    if idx == 10 {
      if sum == self.target {
        self.ret.push(cur.clone());
      }
      return cur;
    }
    for i in 1..=3 {
      cur.push(i);
      cur = self.f(idx + 1, sum + i, cur);
      cur.pop();
    }
    cur
  }

  fn result(&self) -> &Vec<Vec<i32>> {
    &self.ret
  }
}

