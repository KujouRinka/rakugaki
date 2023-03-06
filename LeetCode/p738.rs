impl Solution {
  pub fn monotone_increasing_digits(mut n: i32) -> i32 {
    let mut b = Vec::with_capacity(32);
    while n > 0 {
      b.push(n % 10);
      n /= 10;
    }
    for i in 1..b.len() {
      if b[i] > b[i - 1] {
        b[i] -= 1;
        for j in 0..i {
          b[j] = 9;
        }
      }
    }
    b.reverse();
    b.into_iter()
      .fold(0, |acc, x| acc * 10 + x)
  }
}

