impl Solution {
  pub fn lemonade_change(bills: Vec<i32>) -> bool {
    let mut change = [0; 3];
    for bill in bills.into_iter() {
      if !Self::to_change(&mut change, bill) {
        return false;
      }
    }
    true
  }

  fn to_change(change: &mut [i32], mut i: i32) -> bool {
    change[i as usize / 10] += 1;
    i -= 5;
    for j in (0..=1).rev() {
      let mut m = std::cmp::min(change[j], i / &[5, 10, 20][j]);
      i -= &[5, 10, 20][j] * m;
      change[j] -= m;
    }
    i == 0
  }
}

