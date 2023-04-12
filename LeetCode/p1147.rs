impl Solution {
  pub fn longest_decomposition(text: String) -> i32 {
    let mut s_front = Vec::new();
    let mut s_back = Vec::new();
    let mut p = 0usize;
    let text_len = text.len();
    let rev_p = |x: usize| text_len - 1 - x;

    let mut ret = 0;
    while p < text_len / 2 {
      s_front.push(text.as_bytes()[p]);
      s_back.push(text.as_bytes()[rev_p(p)]);
      if s_front.iter().eq(s_back.iter().rev()) {
        ret += 2;
        s_front.clear();
        s_back.clear();
      }
      p += 1;
    }
    ret + if text_len % 2 == 1 || !s_front.is_empty() {
      1
    } else {
      0
    }
  }
}

