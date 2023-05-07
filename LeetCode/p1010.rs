impl Solution {
  pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
    let mut ret = 0;
    time.into_iter()
      .fold(vec![0; 60], |mut acc, x| {
        let x = x as usize % 60;
        ret += if x == 0 {
          acc[0]
        } else {
          acc[60 - x]
        };
        acc[x] += 1;
        acc
      });
    ret
  }
}

