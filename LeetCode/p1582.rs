impl Solution {
  pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
    if mat.is_empty() {
      return 0;
    }
    let h_record = mat.iter().map(|x| x.iter().sum()).collect::<Vec<i32>>();
    let v_record = (0..mat[0].len()).map(|x| mat.iter().map(|v| v[x]).sum()).collect::<Vec<i32>>();
    (0..mat.len()).fold(
      0, |memo, x| memo + (0..mat[0].len()).filter(
        |&y| mat[x][y] == 1 && h_record[x] == 1 && v_record[y] == 1
      ).count(),
    ) as i32
  }
}

