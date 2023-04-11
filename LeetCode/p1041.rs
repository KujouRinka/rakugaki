const DIRS: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

impl Solution {
  pub fn is_robot_bounded(instructions: String) -> bool {
    let mut dir_idx = 0;
    let (mut x, mut y) = (0, 0);
    for _ in 0..4 {
      for &i in instructions.as_bytes() {
        match i {
          b'G' => {
            x += DIRS[dir_idx].0;
            y += DIRS[dir_idx].1;
          }
          b'L' => dir_idx = (dir_idx + 3) % 4,
          b'R' => dir_idx = (dir_idx + 1) % 4,
          _ => unreachable!(),
        }
      }
      if dir_idx == 0 && x == 0 && y == 0 {
        return true;
      }
    }
    false
  }
}

