use std::cell::Cell;

impl Solution {
  pub fn garden_no_adj(n: i32, paths: Vec<Vec<i32>>) -> Vec<i32> {
    let mut g = vec![Vec::with_capacity(3); n as usize];
    paths.into_iter()
      .for_each(|v| {
        let (x, y) = (v[0] as usize - 1, v[1] as usize - 1);
        g[x].push(y);
        g[y].push(x);
      });
    let mut ret = vec![0; n as usize];
    let rcell = Cell::from_mut(&mut ret[..]).as_slice_of_cells();
    rcell.into_iter()
      .enumerate()
      .for_each(|(i, cell)| {
        let mask = !g[i].iter().fold(0u8, |acc, x| acc | 1 << rcell[*x].get()) & 0b11110;
        cell.set(mask.trailing_zeros() as i32);
      });
    ret
  }
}

