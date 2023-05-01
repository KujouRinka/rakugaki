impl Solution {
  pub fn num_of_minutes(n: i32, head_id: i32, manager: Vec<i32>, inform_time: Vec<i32>) -> i32 {
    let g = manager.into_iter()
      .enumerate()
      .fold(vec![Vec::new(); n as usize], |mut acc, (i, v)| {
        if v != -1 {
          acc[v as usize].push(i);
        }
        acc
      });
    let mut ret = 0;
    let mut q = std::collections::VecDeque::new();
    let mut memo = vec![0; n as usize];
    q.push_back(head_id as usize);
    while !q.is_empty() {
      for _ in 0..q.len() {
        let head = q.pop_front().unwrap();
        for &sub in g[head].iter() {
          if memo[head] + inform_time[head] > memo[sub] {
            memo[sub] = memo[head] + inform_time[head];
            ret = ret.max(memo[sub]);
            q.push_back(sub);
          }
        }
      }
    }
    ret
  }
}

