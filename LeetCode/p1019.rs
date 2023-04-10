// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
  pub fn next_larger_nodes(mut head: Option<Box<ListNode>>) -> Vec<i32> {
    let mut node = Vec::new();
    while let Some(b) = head.take() {
      node.push(b.val);
      head = b.next;
    }
    let mut stack = Vec::with_capacity(node.len());
    let mut ret = vec![0; node.len()];
    for i in 0..node.len() {
      while let Some(idx) = stack.last() {
        if node[*idx] < node[i] {
          ret[*idx] = node[i];
          stack.pop();
        } else {
          break;
        }
      }
      stack.push(i);
    }
    ret
  }
}

