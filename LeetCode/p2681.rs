impl Solution {
  pub fn sum_of_power(mut nums: Vec<i32>) -> i32 {
    let mod_ = 1e9 as u64 + 7;
    nums.sort_unstable();
    let (mut ret, mut pre) = (0, 0);
    for num in nums.into_iter() {
      let num = num as u64;
      ret = (ret + (num * num % mod_) * (pre + num)) % mod_;
      pre = (pre * 2 + num) % mod_;
    }
    ret as i32
  }
}

