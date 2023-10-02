impl Solution {
  pub fn eliminate_maximum(dist: Vec<i32>, speed: Vec<i32>) -> i32 {
    let len = dist.len();
    let mut times = dist.into_iter()
      .zip(speed.into_iter())
      .fold(Vec::with_capacity(len), |mut acc, (d, s)| {
        acc.push((d as f64 / s as f64).ceil() as i32);
        acc
      });
    times.sort_unstable();
    let mut cur_time = 0;
    for time in times.into_iter() {
      if time <= cur_time {
        break;
      }
      cur_time += 1;
    }
    cur_time
  }
}

