impl Solution {
  pub fn mask_pii(s: String) -> String {
    for i in 0..s.len() {
      if unsafe { *s.as_bytes().get_unchecked(i) } == b'@' {
        return Self::email(s, i);
      }
    }
    Self::phone(s)
  }

  fn email(s: String, start: usize) -> String {
    let s = s.to_lowercase();
    let mut ret = String::with_capacity(s.len());
    ret.push_str(&s.as_str()[0..1]);
    ret.push_str("*****");
    ret.push_str(&s.as_str()[start - 1..start]);
    ret.push_str(&s.as_str()[start..]);
    ret
  }

  fn phone(s: String) -> String {
    let filtered: String = s.chars().filter(|x| x.is_ascii_digit()).collect();
    let real_len = filtered.len();
    let last_four = filtered.as_bytes().iter()
      .skip(real_len - 4)
      .take(4)
      .fold(String::with_capacity(4), |mut acc, x| {
        if x.is_ascii_digit() {
          acc.push(*x as char);
        }
        acc
      });
    match real_len {
      10 => format!("***-***-{}", last_four),
      11 => format!("+*-***-***-{}", last_four),
      12 => format!("+**-***-***-{}", last_four),
      13 => format!("+***-***-***-{}", last_four),
      _ => unreachable!()
    }
  }
}

