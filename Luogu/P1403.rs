fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let arg = arg.trim().parse::<usize>().unwrap();
  let mut ret = 0;
  let mut i = 1;
  while i <= arg {
    let base = arg / i;
    let j = arg / base;
    ret += base * (j - i + 1);
    i = j + 1;
  }
  println!("{}", ret);
}

