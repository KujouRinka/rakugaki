impl Solution {
  pub fn frequency_sort(mut nums: Vec<i32>) -> Vec<i32> {
    let mp = nums.iter().fold(std::collections::HashMap::new(), |mut mp, v| {
      *mp.entry(*v).or_insert(0) += 1;
      mp
    });
    nums.sort_by(|x, y| {
      mp[x].cmp(&mp[y]).then(x.cmp(y).reverse())
    });
    nums
  }
}

