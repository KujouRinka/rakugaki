impl Solution {
  pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
    let mut mass = mass as u64;
    asteroids.sort_unstable();
    for i in asteroids {
      if i as u64 > mass {
        return false;
      }
      mass += i as u64;
    }
    true
  }
}

