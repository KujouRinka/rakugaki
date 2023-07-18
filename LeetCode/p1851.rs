use std::collections::BTreeMap;

impl Solution {
  pub fn min_interval(intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
    let mut to_queries = queries.iter()
      .map(|x| (*x, i32::MAX))
      .collect::<BTreeMap<_, _>>();
    intervals.into_iter()
      .for_each(|v| {
        for (_, val) in to_queries.range_mut(v[0]..=v[1]) {
          *val = (v[1] - v[0] + 1).min(*val);
        }
      });
    queries.into_iter()
      .map(|x| if to_queries[&x] == i32::MAX { -1 } else { to_queries[&x] })
      .collect()
  }
}

