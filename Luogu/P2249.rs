fn main() {
  let mut arg = String::new();
  std::io::stdin().read_line(&mut arg).unwrap();
  arg.clear();
  std::io::stdin().read_line(&mut arg).unwrap();
  let nums = arg.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
  arg.clear();
  std::io::stdin().read_line(&mut arg).unwrap();
  let ask = arg.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();

  ask.into_iter()
    .for_each(|x| {
      print!("{} ", match lower_bound(&nums, x) {
        None => { -1 }
        Some(v) => { v as i32 }
      });
    });
}

fn lower_bound(v: &Vec<i32>, i: i32) -> Option<usize> {
  let (mut left, mut right) = (0, v.len());
  while left < right {
    let mid = (left + right) / 2;
    let value = v[mid];
    if i <= value {
      right = mid;
    } else {
      left = mid + 1;
    }
  };
  match v.get(left) {
    None => { None }
    Some(ni) => {
      if *ni == i { Some(left + 1) } else { None }
    }
  }
}

