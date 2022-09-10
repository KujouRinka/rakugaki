fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let arg = arg
    .trim()
    .split_whitespace()
    .map(|x| x.parse::<i32>().unwrap())
    .collect::<Vec<_>>();
  let (n, a, b) = (arg[0], arg[1] - 1, arg[2] - 1);
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let v = arg
    .trim()
    .split_whitespace()
    .take(n as usize)
    .map(|x| x.parse::<i32>().unwrap())
    .collect::<Vec<_>>();

  let mut s = Solution { a, b, v, visited: Vec::new(), times: i32::MAX };
  s.run();
}

struct Solution {
  a: i32,
  b: i32,
  v: Vec<i32>,
  visited: Vec<bool>,
  times: i32,
}

impl Solution {
  fn run(&mut self) {
    self.visited.resize(self.v.len(), false);
    self.dfs(self.a, 0);
    println!("{}", if self.times == i32::MAX { -1 } else { self.times });
  }

  fn dfs(&mut self, cur: i32, jump: i32) {
    if jump > self.times {
      return;
    }
    if cur < 0 || cur >= self.v.len() as i32 {
      return;
    }
    if self.visited[cur as usize] {
      return;
    }
    self.visited[cur as usize] = true;
    if cur == self.b {
      if self.times > jump {
        self.times = jump;
      }
    }
    let next_jp = self.v[cur as usize];
    self.dfs(cur - next_jp, jump + 1);
    self.dfs(cur + next_jp, jump + 1);
    self.visited[cur as usize] = false;
  }
}

