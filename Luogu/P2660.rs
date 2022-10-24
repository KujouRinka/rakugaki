fn main() {
  let mut args = String::new();
  std::io::stdin().read_line(&mut args).unwrap();
  let args: Vec<_> = args.trim().split_ascii_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();
  let (mut height, mut width) = (args[0], args[1]);

  let mut ret = 0;
  while height > 0 && width > 0 {
    let mut add: usize = 0;
    (height, width, add) = helper(height, width);
    ret += add;
  }
  println!("{}", ret);
}

fn helper(height: usize, width: usize) -> (usize, usize, usize) {
  let greater = std::cmp::max(height, width);
  let less = std::cmp::min(height, width);
  (less, greater % less, greater / less * less * 4)
}

