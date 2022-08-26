impl Solution {
  pub fn max_product(nums: Vec<i32>) -> i32 {
    let (mut first, mut second) = (-1, -1);
    for i in nums.into_iter() {
      if i > first {
        second = first;
        first = i;
      } else if i > second {
        second = i;
      }
    }
    (first - 1) * (second - 1)
  }
}

