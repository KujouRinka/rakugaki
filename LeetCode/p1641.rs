impl Solution {
  pub fn count_vowel_strings(n: i32) -> i32 {
    let mut v = vec![vec![0; n as usize + 1]; 5];
    (0..5).for_each(|x| v[x][1] = 1);
    for i in 2..=n as usize {
      let mut ls = 0;
      for j in 0..5 {
        ls += v[j][i - 1];
        v[j][i] = ls;
      }
    }
    (0..5).map(|x| v[x][n as usize]).sum()
  }
}

