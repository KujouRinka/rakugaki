use std::collections::HashMap;

impl Solution {
  pub fn largest_vals_from_labels(values: Vec<i32>, labels: Vec<i32>, num_wanted: i32, use_limit: i32) -> i32 {
    let mut v = values.into_iter()
      .zip(labels.into_iter())
      .collect::<Vec<_>>();
    v.sort_unstable();
    let mut use_static = HashMap::new();
    v.into_iter()
      .rev()
      .fold((0, 0), |(val, num), (value, label)| {
        let use_cnt = use_static.entry(label).or_insert(0);
        if *use_cnt < use_limit && num < num_wanted {
          *use_cnt += 1;
          (val + value, num + 1)
        } else {
          (val, num)
        }
      }).0
  }
}

