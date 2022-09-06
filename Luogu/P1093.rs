use std::cmp::Ordering;

fn main() {
  let mut n = String::new();
  std::io::stdin().read_line(&mut n).unwrap();
  let n = n.trim().parse::<usize>().unwrap();
  let mut v = (1..=n)
    .map(|x| {
      let mut line = String::new();
      std::io::stdin().read_line(&mut line).unwrap();
      let line = line.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
      (x, line)
    })
    .collect::<Vec<(usize, Vec<i32>)>>();

  v.sort_by(|x, y| {
    let order = x.1.iter().sum::<i32>().cmp(&y.1.iter().sum::<i32>());
    if let Ordering::Equal = order {
      let order = x.1[0].cmp(&y.1[0]);
      if let Ordering::Equal = order {
        x.0.cmp(&y.0).reverse()
      } else {
        order
      }
    } else {
      order
    }
  });

  v.iter().rev().take(5).for_each(|x| {
    println!("{} {}", x.0, x.1.iter().sum::<i32>());
  });
}

