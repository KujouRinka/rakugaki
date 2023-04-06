impl Solution {
  pub fn base_neg2(n: i32) -> String {
    if n == 0 {
      return "0".into()
    }
    let mut n = n;
    let mut ret = String::with_capacity(32);
    while n != 0 {
      let bit = if n % -2 >= 0 {
        let ret = (n % -2).to_string();
        n /= -2;
        ret
      } else {
        n /= -2;
        n += 1;
        "1".into()
      };
      ret.push_str(&bit);
    }
    ret.chars().into_iter().rev().collect()
  }
}

