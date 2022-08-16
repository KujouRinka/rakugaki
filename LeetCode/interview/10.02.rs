use std::collections::HashMap;

impl Solution {
  pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut map: HashMap<Vec<char>, Vec<String>> = HashMap::new();
    for s in strs {
      let mut k: Vec<char> = s.chars().collect();
      k.sort_unstable();
      let v = map.entry(k).or_insert(Vec::new());
      v.push(s)
    }
    map.into_iter().map(move |(k, v)| v).collect()
  }
}

