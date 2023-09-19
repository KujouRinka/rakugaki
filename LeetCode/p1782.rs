use std::collections::HashMap;

impl Solution {
  pub fn count_pairs(n: i32, mut edges: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
    let mut edge_cnt = vec![0; n as usize + 1];
    let edge_hash = edges.iter_mut()
      .fold(HashMap::new(), |mut acc, mut x| {
        edge_cnt[x[0] as usize] += 1;
        edge_cnt[x[1] as usize] += 1;
        if x[0] > x[1] {
          x.swap(0, 1);
        }
        *acc.entry(x[0] << 16 | x[1]).or_insert(0) += 1;
        acc
      });
    let mut edge_cnt_sorted = edge_cnt.clone();
    edge_cnt_sorted.sort_unstable();
    queries.into_iter()
      .fold(vec![], |mut acc, query| {
        let mut to_push = 0;
        let (mut left, mut right) = (1, n);
        while left < right {
          if edge_cnt_sorted[left as usize] + edge_cnt_sorted[right as usize] <= query {
            left += 1;
          } else {
            to_push += right - left;
            right -= 1;
          }
        }
        edge_hash.iter()
          .for_each(|x| {
            let k = *x.0;
            let s = edge_cnt[k as usize >> 16] + edge_cnt[k as usize & 0xffff];
            if s > query && s - *x.1 <= query {
              to_push -= 1;
            }
          });
        acc.push(to_push);
        acc
      })
  }
}

