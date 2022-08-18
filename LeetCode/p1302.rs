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

struct SolutionHelper {
  ret: i32,
  max_depth: i32,
}

impl Solution {
  pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut s = SolutionHelper::new();
    s.run(&root, 0);
    s.ret
  }
}

impl SolutionHelper {
  fn new() -> Self {
    SolutionHelper {
      ret: 0,
      max_depth: 0,
    }
  }

  fn run(&mut self, root: &Option<Rc<RefCell<TreeNode>>>, depth: i32) {
    match root {
      Some(s) => {
        if self.max_depth == depth {
          self.ret += s.borrow().val;
        } else if self.max_depth < depth {
          self.max_depth = depth;
          self.ret = s.borrow().val;
        }
        self.run(&s.borrow().left, depth + 1);
        self.run(&s.borrow().right, depth + 1);
      },
      None => { return; },
    }
  }
}

