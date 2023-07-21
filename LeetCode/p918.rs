impl Solution {
  pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
    let vec_sum = nums.iter().sum::<i32>();
    let t = nums.iter()
      .fold(((0, i32::MIN), (0, i32::MIN)), |((acc, ret), (acc2, ret2)), x| {
        let ma = if acc < 0 {
          (*x, ret.max(*x))
        } else {
          (acc + *x, ret.max(acc + *x))
        };
        let mi = if acc2 < 0 {
          (-*x, ret2.max(-*x))
        } else {
          (acc2 - *x, ret2.max(acc2 - *x))
        };
        (ma, mi)
      });
    if t.0.1 < 0 {
      t.0.1
    } else {
      std::cmp::max(t.0.1, vec_sum + t.1.1)
    }
  }
}

