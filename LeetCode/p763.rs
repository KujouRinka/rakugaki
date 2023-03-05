impl Solution {
  pub fn partition_labels(s: String) -> Vec<i32> {
    let mut last_table = [0 as usize; 26];
    for i in 0..s.as_bytes().len() {
      last_table[(s.as_bytes()[i] - b'a') as usize] = i + 1;
    }
    let mut ret = Vec::new();
    let mut start = 0;
    let mut end = 0;
    while start < s.len() {
      let mut memo = last_table[(s.as_bytes()[start] - b'a') as usize];
      while end < s.len() && end < memo {
        memo = memo.max(last_table[(s.as_bytes()[end] - b'a') as usize]);
        end += 1;
      }
      ret.push((end - start) as i32);
      start = end;
    }
    ret
  }
}

