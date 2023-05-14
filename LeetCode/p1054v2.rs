use std::collections::{BinaryHeap, HashMap};

struct Next {
  hp: BinaryHeap<(i32, i32)>,
  tp: (i32, i32),
}

impl Next {
  fn new(hp: BinaryHeap<(i32, i32)>) -> Self {
    Self {
      hp,
      tp: (0, 0),
    }
  }

  fn next(&mut self) -> i32 {
    if self.tp.0 == 0 {
      self.tp = self.hp.pop().unwrap();
    }
    let ret = self.tp.1;
    self.tp.0 -= 1;
    ret
  }
}

impl Solution {
  pub fn rearrange_barcodes(barcodes: Vec<i32>) -> Vec<i32> {
    let b_len = barcodes.len();
    let mut hp = barcodes.into_iter()
      .fold(HashMap::new(), |mut acc, x| {
        *acc.entry(x).or_insert(0) += 1;
        acc
      })
      .into_iter()
      .map(|x| (x.1, x.0))
      .collect::<BinaryHeap<_>>();
    let mut n = Next::new(hp);
    let mut ret = vec![0; b_len];
    for i in std::iter::successors(Some(0), |n| if n + 2 < b_len { Some(n + 2) } else { None }) {
      ret[i] = n.next();
    }
    for i in std::iter::successors(if b_len > 1 { Some(1) } else { None }, |n| if n + 2 < b_len { Some(n + 2) } else { None }) {
      ret[i] = n.next();
    }
    ret
  }
}

