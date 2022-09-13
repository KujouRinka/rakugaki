use std::alloc::{alloc, dealloc, Layout};
use std::collections::HashMap;
use std::ptr::null_mut;

struct List {
  head: *mut Node,
}

struct Node {
  val: i32,
  left: *mut Node,
  right: *mut Node,
}

impl List {
  const LAYOUT: Layout = Layout::new::<Self>();

  fn new() -> Self {
    List { head: null_mut() }
  }

  fn insert_init(&mut self, v: i32) -> *mut Node {
    if !self.head.is_null() {
      return null_mut();
    }
    let new_node = Self::new_node();
    unsafe {
      (*new_node).val = v;
      self.head = new_node;
    }
    new_node
  }

  fn insert(&mut self, pos: *mut Node, v: i32, w: i32) -> *mut Node {
    let new_node = Self::new_node();
    unsafe {
      (*new_node).val = v;
      if w == 0 {
        (*new_node).left = (*pos).left;
        (*new_node).right = pos;
        if !(*new_node).left.is_null() {
          (*(*new_node).left).right = new_node;
        }
        (*pos).left = new_node;
        if pos == self.head {
          self.head = new_node;
        }
      } else if w == 1 {
        (*new_node).right = (*pos).right;
        (*new_node).left = pos;
        if !(*new_node).right.is_null() {
          (*(*new_node).right).left = new_node;
        }
        (*pos).right = new_node;
      }
    }
    new_node
  }

  fn remove(&mut self, pos: *mut Node) {
    unsafe {
      if pos == self.head {
        self.head = (*pos).right;
      }
      if !(*pos).left.is_null() {
        (*(*pos).left).right = (*pos).right;
      }
      if !(*pos).right.is_null() {
        (*(*pos).right).left = (*pos).left;
      }
    }
    Self::free_node(pos);
  }

  fn new_node() -> *mut Node {
    unsafe {
      let n = alloc(Self::LAYOUT) as *mut Node;
      (*n).left = null_mut();
      (*n).right = null_mut();
      n
    }
  }

  fn free_node(n: *mut Node) {
    unsafe { dealloc(n as *mut u8, Self::LAYOUT) };
  }

  fn visit(&self) {
    let mut n = self.head;
    unsafe {
      while !n.is_null() {
        print!("{} ", (*n).val);
        n = (*n).right;
      }
    }
  }
}

impl Drop for List {
  fn drop(&mut self) {}
}

fn main() {
  let mut n = String::new();
  std::io::stdin().read_line(&mut n).unwrap();
  let n = n.trim().parse::<usize>().unwrap();
  let mut m = HashMap::<i32, *mut Node>::with_capacity(n);
  let mut lst = List::new();
  m.insert(1, lst.insert_init(1));
  for i in 2..=n {
    let mut v = String::new();
    std::io::stdin().read_line(&mut v).unwrap();
    let v = v.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<_>>();
    let (k, p) = (v[0], v[1]);
    m.insert(i as i32, lst.insert(*m.get(&k).unwrap(), i as i32, p));
  }
  let mut n = String::new();
  std::io::stdin().read_line(&mut n).unwrap();
  let n = n.trim().parse::<usize>().unwrap();
  for _ in 0..n {
    let mut who = String::new();
    std::io::stdin().read_line(&mut who).unwrap();
    let who = who.trim().parse::<i32>().unwrap();
    if m.contains_key(&who) {
      lst.remove(*m.get(&who).unwrap());
      m.remove(&who);
    }
  }
  lst.visit();
  println!();
}

