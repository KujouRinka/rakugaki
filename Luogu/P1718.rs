fn main() {
  let mut line = String::new();
  std::io::stdin().read_line(&mut line).unwrap();
  let line = line.trim().parse::<usize>().unwrap();

  let mut max_len = 0;
  let nums = (1..=line)
    .map(|x| {
      let mut arg = String::new();
      std::io::stdin().read_line(&mut arg).unwrap();
      max_len = std::cmp::max(max_len, arg.len());
      (x, arg)
    })
    .collect::<Vec<_>>();

  let nums = nums
    .iter()
    .filter(|x| x.1.len() == max_len)
    .collect::<Vec<_>>();

  let result = nums
    .iter()
    .max_by(|lhs, rhs| {
      let lhs = &lhs.1;
      let rhs = &rhs.1;
      lhs.as_str().cmp(rhs.as_str())
    }).unwrap();
  println!("{}\n{}", result.0, result.1);
}

