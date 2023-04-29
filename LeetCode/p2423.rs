impl Solution {
  pub fn equal_frequency(word: String) -> bool {
    let mut table = word.as_bytes()
      .iter()
      .fold(vec![0; 26], |mut acc, &ch| {
        acc[(ch - b'a') as usize] += 1;
        acc
      });
    for &ch in word.as_bytes().iter() {
      let idx = (ch - b'a') as usize;
      table[idx] -= 1;
      let c = table[idx];
      if table.iter().filter(|x| **x != 0).collect::<Vec<_>>().windows(2)
        .fold(
          true, |acc, x| {
            if !acc || x[0] != x[1] {
              false
            } else {
              true
            }
          },
        ) {
        return true;
      }
      table[idx] += 1;
    }
    false
  }
}

