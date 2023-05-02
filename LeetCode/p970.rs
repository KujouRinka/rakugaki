impl Solution {
  pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
    let mut set = std::collections::HashSet::<i32>::new();
    for i in std::iter::repeat(0).scan(1, |acc, _| {
      if *acc > bound {
        None
      } else {
        let ret = Some(*acc);
        *acc *= x;
        ret
      }
    }) {
      for j in std::iter::repeat(0).scan(1, |acc, _| {
        if *acc + i > bound {
          None
        } else {
          let ret = Some(*acc);
          *acc *= y;
          ret
        }
      }) {
        set.insert(i + j);
        if y == 1 {
          break;
        }
      }
      if x == 1 {
        break;
      }
    }
    set.into_iter().collect()
  }
}

