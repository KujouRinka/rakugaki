// api practice
use std::collections::VecDeque;

struct MyCircularDeque {
  capacity: usize,
  deque: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCircularDeque {
  fn new(k: i32) -> Self {
    MyCircularDeque {
      capacity: k as usize,
      deque: VecDeque::with_capacity(k as usize),
    }
  }

  fn insert_front(&mut self, value: i32) -> bool {
    if self.deque.len() >= self.capacity {
      return false;
    }
    self.deque.push_front(value);
    true
  }

  fn insert_last(&mut self, value: i32) -> bool {
    if self.deque.len() >= self.capacity {
      return false;
    }
    self.deque.push_back(value);
    true
  }

  fn delete_front(&mut self) -> bool {
    match self.deque.pop_front() {
      Some(_) => true,
      None => false,
    }
  }

  fn delete_last(&mut self) -> bool {
    match self.deque.pop_back() {
      Some(_) => true,
      None => false,
    }
  }

  fn get_front(&self) -> i32 {
    match self.deque.front() {
      Some(v) => v.clone(),
      None => -1,
    }
  }

  fn get_rear(&self) -> i32 {
    match self.deque.back() {
      Some(v) => v.clone(),
      None => -1,
    }
  }

  fn is_empty(&self) -> bool {
    return self.deque.is_empty();
  }

  fn is_full(&self) -> bool {
    return self.deque.len() == self.capacity;
  }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * let obj = MyCircularDeque::new(k);
 * let ret_1: bool = obj.insert_front(value);
 * let ret_2: bool = obj.insert_last(value);
 * let ret_3: bool = obj.delete_front();
 * let ret_4: bool = obj.delete_last();
 * let ret_5: i32 = obj.get_front();
 * let ret_6: i32 = obj.get_rear();
 * let ret_7: bool = obj.is_empty();
 * let ret_8: bool = obj.is_full();
 */

