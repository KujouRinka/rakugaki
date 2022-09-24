use std::cmp::Reverse;

fn main() {
  let mut args = String::new();
  std::io::stdin().read_line(&mut args).unwrap();
  let args = args.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
  let mut g = (0..=args[0]).collect::<Vec<_>>();
  let mut enemy = Vec::with_capacity(args[0] as usize + 1);
  enemy.resize(enemy.capacity(), 0);
  let mut ang = (0..args[1]).map(|_| {
    let mut args = String::new();
    std::io::stdin().read_line(&mut args).unwrap();
    let args = args.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    (args[0], args[1], args[2])
  }).collect::<Vec<_>>();
  ang.sort_by_key(|x| Reverse(x.2));

  for x in ang.into_iter() {
    if conflict(&mut g, x.0, x.1) {
      println!("{}", x.2);
      return;
    }
    if enemy[x.0] == 0 {
      enemy[x.0] = x.1;
    } else {
      add(&mut g, enemy[x.0], x.1);
    }
    if enemy[x.1] == 0 {
      enemy[x.1] = x.0;
    } else {
      add(&mut g, enemy[x.1], x.0)
    }
  }
  println!("{}", 0);
  ()
}

fn find(v: &mut Vec<usize>, x: usize) -> usize {
  if v[x] == x {
    return x;
  }
  v[x] = find(v, v[x]);
  v[x]
}

fn add(v: &mut Vec<usize>, x: usize, y: usize) {
  let nx = find(v, x);
  let ny = find(v, y);
  v[nx] = v[ny];
}

fn conflict(v: &mut Vec<usize>, x: usize, y: usize) -> bool {
  let nx = find(v, x);
  let ny = find(v, y);
  nx == ny
}

