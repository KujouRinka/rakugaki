use std::cmp::max;

fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let arg = arg.trim().parse::<usize>().unwrap();

  let mut v = Vec::with_capacity(arg + 1);
  v.push(Vec::new());
  let v = (0..arg).fold(v, |mut v, x| {
    let mut arg = String::new();
    std::io::stdin().read_line(&mut arg).unwrap();
    let node = arg.trim()
      .split_whitespace()
      .map(|x| x.parse::<usize>().unwrap())
      .collect::<Vec<_>>();
    v.push(node);
    v
  });
  println!("{}", depth(1, &v));
}

fn depth(id: usize, data: &Vec<Vec<usize>>) -> usize {
  if id == 0 {
    return 0;
  }
  max(depth(data[id][0], data), depth(data[id][1], data)) + 1
}

