// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
  pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
    let mut ret = Vec::<Vec<i32>>::new();
    Self::helper(&root, &mut ret);
    ret
  }

  fn helper(root: &Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<Vec<i32>>) {
    if root.is_none() {
      return;
    }
    let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::from([root.as_ref().unwrap().clone()]);
    while !queue.is_empty() {
      let mut tv: Vec<i32> = Vec::new();
      for _ in 0..queue.len() {
        let rc = queue.pop_front().unwrap();
        tv.push(rc.borrow().val.clone());
        if let Some(rc) = &rc.borrow().left {
          queue.push_back(rc.clone());
        };
        if let Some(rc) = &rc.borrow().right {
          queue.push_back(rc.clone());
        };
      }
      v.push(tv);
    }
  }
}

