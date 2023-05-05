impl Solution {
  pub fn is_valid(s: String) -> bool {
    let mut stack = Vec::new();
    for &ch in s.as_bytes() {
      match ch {
        b'a' => {
          stack.push(b'a');
        }
        b'b' => {
          match stack.last() {
            Some(&ch) if ch == b'a' => stack.push(b'b'),
            _ => return false,
          }
        }
        b'c' => {
          if stack.len() < 2 {
            return false;
          }
          if stack.pop().unwrap() != b'b' || stack.pop().unwrap() != b'a' {
            return false;
          }
        }
        _ => unreachable!(),
      }
    }
    return stack.is_empty();
  }
}

