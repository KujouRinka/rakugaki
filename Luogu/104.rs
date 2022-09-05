use std::collections::{HashMap, HashSet};

fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  let mut memo = HashMap::<u8, i32>::with_capacity(26);
  for &ch in arg.trim().as_bytes() {
    *memo.entry(ch).or_insert(0) += 1;
  }
  let (mut maxn, mut minn) = (0, 101);
  for &v in memo.values() {
    maxn = std::cmp::max(maxn, v);
    minn = std::cmp::min(minn, v);
  }
  let prime_watch = HashSet::from([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]);
  let is_prime = move |x| {
    prime_watch.contains(&x)
  };
  let (hint, val) = if is_prime(maxn - minn) {
    ("Lucky Word", maxn - minn)
  } else {
    ("No Answer", 0)
  };
  println!("{}\n{}", hint, val);
}

