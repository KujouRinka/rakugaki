use std::collections::VecDeque;

impl Solution {
  pub fn reconstruct_queue(mut people: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    people.sort_unstable_by(|l, r| {
      r[0].cmp(&l[0]).then(l[1].cmp(&r[1]))
    });
    let mut ret: VecDeque<Vec<i32>> = VecDeque::with_capacity(people.len());
    people.into_iter()
      .for_each(|x| {
        ret.insert(x[1] as usize, x);
      });
    ret.into()
  }
}

