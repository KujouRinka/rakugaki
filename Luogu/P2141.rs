use std::collections::HashSet;

fn main() {
  let mut arg1 = String::new();
  std::io::stdin().read_line(&mut arg1).unwrap();
  let arg1: i32 = arg1.trim().parse().unwrap();
  let mut arg2 = String::new();
  std::io::stdin().read_line(&mut arg2).unwrap();
  let arg2: Vec<_> = arg2.trim().split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
  let mut argx: HashSet<_> = arg2.iter().collect();
  let all = argx.len();
  for i in 0..arg2.len() {
    for j in (i + 1)..arg2.len() {
      let sum = arg2[i] + arg2[j];
      if argx.contains(&sum) {
        argx.remove(&sum);
      }
    }
  }
  println!("{}", all - argx.len());
}

