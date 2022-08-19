impl Solution {
  pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
    start_time.into_iter().zip(end_time.into_iter()).filter(|x| {
      x.0 <= query_time && x.1 >= query_time
    }).count() as i32
  }
}

