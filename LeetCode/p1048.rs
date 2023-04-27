use std::collections::{BTreeMap, HashMap, HashSet};

impl Solution {
  pub fn longest_str_chain(words: Vec<String>) -> i32 {
    let table = words.into_iter()
      .fold(BTreeMap::<usize, HashSet<String>>::new(), |mut acc, x| {
        acc.entry(x.len()).or_insert(HashSet::new()).insert(x);
        acc
      });
    let mut dp = vec![HashMap::<String, usize>::new(); table.len()];
    // init dp
    for (i, (_, v)) in table.iter().enumerate() {
      for s in v {
        dp[i].insert(s.clone(), 1);
      }
    }
    let mut ret = 1;
    for (dpi, (i, v)) in table.iter().enumerate() {
      if let Some(lv) = table.get(&(i - 1)) {
        for cur_s in v {
          dp[dpi].insert(cur_s.clone(), 1);
          for pre_s in Self::is_prede_of(cur_s, lv) {
            let pre_len = dp[dpi - 1][pre_s];
            if dp[dpi][cur_s] < pre_len + 1 {
              *dp[dpi].get_mut(cur_s).unwrap() = pre_len + 1;
            }
            ret = ret.max(dp[dpi][cur_s]);
          }
        }
      }
    }
    ret as i32
  }

  fn is_prede_of<'a>(s: &str, set: &'a HashSet<String>) -> Vec<&'a str> {
    let mut ret = vec![];
    for i in 0..s.len() {
      let mut tmp = s.to_string();
      tmp.remove(i);
      if set.contains(&tmp) {
        ret.push(set.get(&tmp).unwrap().as_str());
      }
    }
    ret
  }
}

