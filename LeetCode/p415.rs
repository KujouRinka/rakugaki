use std::iter;

impl Solution {
  pub fn add_strings(num1: String, num2: String) -> String {
    let ret = num1.as_bytes()
      .into_iter()
      .rev()
      .map(|x| *x - b'0')
      .chain(iter::repeat(0).take(std::cmp::max(0, num2.len() as i32 - num1.len() as i32) as usize + 1))
      .zip(
        num2.as_bytes()
          .into_iter()
          .rev()
          .map(|x| *x - b'0')
          .chain(iter::repeat(0).take(std::cmp::max(0, num1.len() as i32 - num2.len() as i32) as usize + 1))
      )
      .fold((0, vec![]), |(carry, mut result), (a, b)| {
        let sum = (a + b) + carry;
        result.push(sum % 10);
        (sum / 10, result)
      })
      .1
      .into_iter()
      .rev()
      .skip_while(|x| *x == 0)
      .map(|x| (x + b'0') as char)
      .collect::<String>();
    if ret.is_empty() { "0".into() } else { ret }
  }
}

