// author: yqq
// date: 2021-05-24 19:33:09
// descriptions: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

struct Solution {}

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {

        let retHead = &head;
        let mut p1 = &head; 
        let mut p2 = &head ;

        let mut i = 0;
        while i < n && !p1.is_none() {
            p1 = &p1.as_ref().unwrap().next;
            i += 1;
        }
        p1 = &p1.as_ref().unwrap().next;

        if(p1.is_none() && i == n - 1) {
            return head.unwrap().next;
        }

        while !p1.is_none() {
            p1 = &p1.as_ref().unwrap().next;
            p2 = &p2.as_ref().unwrap().next;
        }

        // p2.as_ref().unwrap().next.as_mut() = p2.as_ref().unwrap().next.unwrap().next;
        return *retHead.as_ref();
    }
}


fn main(){

    let mut node2: ListNode = ListNode::new(2);
    let mut node1: ListNode = ListNode::new(1);
    node1.next = Some(Box::new(node2));


    println!("hello world")
}

