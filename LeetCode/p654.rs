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
use std::cell::{Ref, RefCell};

impl Solution {
  pub fn construct_maximum_binary_tree(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
    let mut stk: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
    for i in nums.into_iter() {
      let mut nrc = Some(Rc::new(RefCell::new(TreeNode::new(i))));
      if let Some(item) = stk.last_mut() {
        if let Some(rc) = item {
          if rc.borrow().val > i {
            rc.borrow_mut().right = nrc.clone();
            stk.push(nrc);
          } else {
            let mut op: Option<Rc<RefCell<TreeNode>>> = None;
            while let Some(rc) = stk.pop() {
              if rc.as_ref().unwrap().borrow().val > i {
                op = rc;
                break;
              }
              nrc.as_ref().unwrap().borrow_mut().left = rc;
            }
            if let Some(rc) = op.as_ref() {
              rc.borrow_mut().right = nrc.clone();
              stk.push(op);
            }
            stk.push(nrc);
          }
        }
      } else {
        stk.push(nrc);
      }
    }
    stk.first_mut().unwrap().take()
  }
}

