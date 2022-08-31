impl Solution {
  pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
    let mut mock_vec = Vec::with_capacity(pushed.len());
    let mut popped_idx = 0;
    for i in pushed.into_iter() {
      mock_vec.push(i);
      while let Some(j) = mock_vec.last() {
        if *j != popped[popped_idx] {
          break;
        }
        popped_idx += 1;
        mock_vec.pop();
      }
    }
    mock_vec.is_empty()
  }
}

