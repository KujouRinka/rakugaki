use std::collections::{BinaryHeap, HashMap};

impl Solution {
  pub fn rearrange_barcodes(barcodes: Vec<i32>) -> Vec<i32> {
    let mut ret = Vec::with_capacity(barcodes.len());
    let mut hp = barcodes.into_iter()
      .fold(HashMap::new(), |mut acc, x| {
        *acc.entry(x).or_insert(0) += 1;
        acc
      })
      .into_iter()
      .map(|x| (x.1, x.0))
      .collect::<BinaryHeap<_>>();
    while let Some(mut t0) = hp.pop() {
      if let Some(mut t1) = hp.pop() {
        if let Some(b) = ret.last() {
          if *b == t0.1 {
            core::mem::swap(&mut t0, &mut t1);
          }
        }

        ret.push(t0.1);
        t0.0 -= 1;
        if t0.0 != 0 {
          hp.push(t0);
        }

        ret.push(t1.1);
        t1.0 -= 1;
        if t1.0 != 0 {
          hp.push(t1);
        }
      } else {
        ret.push(t0.1);
        t0.0 -= 1;
        if t0.0 != 0 {
          hp.push(t0);
        }
      }
    }
    ret
  }
}

