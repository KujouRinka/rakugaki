impl Solution {
  pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
    g.sort_unstable();
    s.sort_unstable();
    let mut iter = s.into_iter();
    g.into_iter().fold(0, |acc, x| {
      while let Some(i) = iter.next() {
        if i >= x {
          return acc + 1;
        }
      }
      acc
    })
  }
}

