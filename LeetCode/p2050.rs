impl Solution {
  pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
    use std::collections::VecDeque;

    let (from_to, mut ins) = relations.into_iter()
      .fold((vec![vec![]; n as usize], vec![0; n as usize]), |(mut from_to, mut ins), x| {
        from_to[x[0] as usize - 1].push(x[1] as usize - 1);
        ins[x[1] as usize - 1] += 1;
        (from_to, ins)
      });
    let (mut queue, mut dp) = ins.iter()
      .enumerate()
      .filter(|x| *x.1 == 0)
      .fold((VecDeque::new(), vec![0; n as usize]), |(mut queue, mut dp), x| {
        queue.push_back(x.0);
        dp[x.0] = time[x.0];
        (queue, dp)
      });

    let mut ret = 0;
    while let Some(v) = queue.pop_front() {
      from_to[v].iter().for_each(|x| {
        dp[*x] = dp[*x].max(dp[v] + time[*x]);
        ins[*x] -= 1;
        if ins[*x] == 0 {
          queue.push_back(*x);
        }
      });
      ret = ret.max(dp[v]);
    }
    ret
  }
}

