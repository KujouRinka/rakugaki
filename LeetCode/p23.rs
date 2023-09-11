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
  pub fn merge_k_lists(mut lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    if lists.len() == 0 {
      return None;
    }
    loop {
      let l1 = lists.pop().unwrap();
      let l2 = match lists.pop() {
        Some(v) => v,
        None => return l1,
      };
      lists.push(Self::merge_2(l1, l2));
    }
    unreachable!()
  }

  pub fn merge_2(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut dummy = Box::new(ListNode{ val: 0, next: None });
    let mut option_ref = &mut dummy.next;
    while l1.is_some() && l2.is_some() {
      let (v1, v2) = (l1.as_ref().unwrap().val, l2.as_ref().unwrap().val);
      *option_ref = if v1 > v2 {
        let tl2 = l2.as_mut().unwrap().next.take();
        let ret = l2;
        l2 = tl2;
        ret
      } else {
        let tl1 = l1.as_mut().unwrap().next.take();
        let ret = l1;
        l1 = tl1;
        ret
      };
      option_ref = &mut option_ref.as_mut().unwrap().next;
    }
    if l1.is_some() {
      *option_ref = l1;
    }
    if l2.is_some() {
      *option_ref = l2;
    }
    dummy.next
  }
}

