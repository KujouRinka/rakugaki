use std::collections::HashMap;

impl Solution {
  pub fn smallest_sufficient_team(req_skills: Vec<String>, people: Vec<Vec<String>>) -> Vec<i32> {
    let sk_len = req_skills.len();
    assert!(sk_len <= 16);
    // Map skills to bin
    let req_skill_map = req_skills.into_iter()
      .fold((1, HashMap::with_capacity(sk_len)), |(bit, mut map), x| {
        map.insert(x, bit);
        (bit << 1, map)
      }).1;
    let people_map = people.into_iter()
      .map(|x| {
        x.into_iter()
          .fold(0, |acc, y| {
            acc | req_skill_map.get(&y).unwrap()
          })
      })
      .collect::<Vec<_>>();
    let mut dp = vec![vec![0u64; 1 << sk_len]; people_map.len() + 1];
    // init dp
    dp[0].fill((1 << people_map.len()) - 1);
    dp[0][0] = 0;
    for i in 1..=people_map.len() {
      for j in 1..(1 << sk_len) {
        let s1: u64 = dp[i - 1][j];
        let s2 = dp[i - 1][(j & !(people_map[i - 1] as usize))] | (1 << i - 1);
        dp[i][j] = if s1.count_ones() < s2.count_ones() { s1 } else { s2 };
      }
    }
    let to_convert = dp[people_map.len()][(1 << sk_len) - 1];
    let mut ret = vec![];
    for i in 0..people_map.len() {
      if to_convert & (1 << i) != 0 {
        ret.push(i as i32);
      }
    }
    ret
  }
}

