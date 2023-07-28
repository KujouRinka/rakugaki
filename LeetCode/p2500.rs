impl Solution {
  pub fn delete_greatest_value(grid: Vec<Vec<i32>>) -> i32 {
    use std::cmp::Reverse;

    let mut grid = grid;
    grid.iter_mut()
      .for_each(|x| x.sort_unstable_by_key(|x| Reverse(*x)));
    (0..grid[0].len()).fold(0, |acc, x| {
      acc + grid.iter().map(|v| v[x]).max().unwrap()
    })
  }
}

