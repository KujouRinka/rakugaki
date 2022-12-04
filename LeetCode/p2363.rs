use std::collections::BTreeMap;

impl Solution {
  pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mp: BTreeMap<_, _> =
      items1.into_iter()
        .map(|v| (v[0], v[1]))
        .collect();
    let mp = items2.into_iter()
      .fold(mp, |mut acc, v| {
        *acc.entry(v[0]).or_insert(0) += v[1];
        acc
      });
    mp.into_iter().map(|(k, v)| vec![k, v]).collect()
  }
}

