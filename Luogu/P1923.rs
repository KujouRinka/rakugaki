// enable O2 for AC
fn main() {
  let mut args1 = String::new();
  std::io::stdin().read_line(&mut args1).unwrap();
  let args1 = args1.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
  let args1 = args1[1] as usize;
  let mut args2 = String::new();
  std::io::stdin().read_line(&mut args2).unwrap();
  let mut args2 = args2.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
  let (mut lower, mut upper) = (0, args2.len());
  println!("{}", loop {
    let p = partition(&mut args2, lower, upper);
    if p > args1 {
      upper = p;
    } else if p < args1 {
      lower = p + 1;
    } else {
      break args2[p];
    }
  });
}

fn partition(v: &mut Vec<i32>, lower: usize, upper: usize) -> usize {
  let pivot = v[lower];
  let (mut left, mut right) = (lower, upper - 1);
  while left < right {
    while left < right && pivot < v[right] {
      right -= 1;
    }
    v.swap(left, right);
    while left < right && v[left as usize] <= pivot {
      left += 1;
    }
    v.swap(left, right);
  }
  v[left] = pivot;
  left
}

