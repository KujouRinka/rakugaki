impl Solution {
  pub fn sample_stats(count: Vec<i32>) -> Vec<f64> {
    let (mut min, mut max, mut mean, mut mid, mut mode) = (-1, -1, 0f64, 0f64, 0);
    let mut sum_acc = 0u64;
    let mut cnt_acc = 0u64;
    let mut mode_acc = 0u64;
    for (i, &x) in count.iter().enumerate() {
      let x = x as u64;
      if x != 0 {
        max = i as i32;
        if min == -1 {
          min = i as i32;
        }
      }
      if x > mode_acc {
        mode = i;
        mode_acc = x;
      }
      sum_acc += i as u64 * x as u64;
      cnt_acc += x;
    }
    mean = sum_acc as f64 / cnt_acc as f64;
    let mut to_find = if cnt_acc & 1 == 1 {
      (cnt_acc >> 1) + 1
    } else {
      cnt_acc >> 1
    };
    let mut i = 0;
    while to_find > count[i] as u64 {
      to_find -= count[i] as u64;
      i += 1;
    }
    if cnt_acc & 1 == 1 {
      mid = i as f64;
    } else {
      let left = i;
      let right = if to_find == count[i] as u64 {
        i += 1;
        while count[i] == 0 {
          i += 1;
        }
        i
      } else {
        i
      };
      mid = (left + right) as f64 / 2f64
    }
    vec![min as f64, max as f64, mean, mid, mode as f64]
  }
}

