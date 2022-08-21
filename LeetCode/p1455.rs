impl Solution {
  pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
    let v: Vec<_> = sentence.split(' ').collect();
    let mut ret = 1;
    for s in v.into_iter() {
      if s.starts_with(&search_word) {
        return ret;
      }
      ret += 1;
    }
    return -1;
  }
}

