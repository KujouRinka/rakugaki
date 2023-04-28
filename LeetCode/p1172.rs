use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct DinnerPlates {
  v: Vec<Vec<i32>>,
  cap: usize,
  min_unfull: BinaryHeap<Reverse<usize>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl DinnerPlates {
  fn new(capacity: i32) -> Self {
    Self {
      v: Vec::new(),
      cap: capacity as usize,
      min_unfull: BinaryHeap::from(vec![Reverse(0)]),
    }
  }

  fn push(&mut self, val: i32) {
    while let Some(&idx) = self.min_unfull.peek() {
      match self.v.get_mut(idx.0) {
        Some(stack) if stack.len() < self.cap => {
          stack.push(val);
          if stack.len() == self.cap {
            let to_push = Reverse(self.min_unfull.pop().unwrap().0 + 1);
            self.min_unfull.push(to_push);
          }
          return;
        }
        Some(_) => { self.min_unfull.pop(); }
        None => {
          self.v.push(Vec::with_capacity(self.cap));
        }
      }
    }
  }

  fn pop(&mut self) -> i32 {
    while let Some(stack) = self.v.last_mut() {
      if let Some(v) = stack.pop() {
        self.min_unfull.push(Reverse(self.v.len() - 1));
        return v;
      }
      self.v.pop();
    }
    return -1;
  }

  fn pop_at_stack(&mut self, index: i32) -> i32 {
    let index = index as usize;
    if index >= self.v.len() {
      return -1;
    }
    self.min_unfull.push(Reverse(index));
    self.v.get_mut(index).unwrap().pop().unwrap_or(-1)
  }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * let obj = DinnerPlates::new(capacity);
 * obj.push(val);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.pop_at_stack(index);
 */

