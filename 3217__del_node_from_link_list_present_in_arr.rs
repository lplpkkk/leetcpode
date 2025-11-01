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

use std::collections::HashSet;
/*
impl Solution {
    pub fn add_to_hs(nums:Vec<i32>){
        let mut hs=HashSet::new();
        for num in nums{
            hs.insert(num);
        }
    }

    pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        add_to_hs(nums);
        Box ans=Box::new();
        
        while head{
            if hs.contains(&head->val){
                //remove this node
                head=
            }
            head=head->next;
        }    
        ans
    }
}
*/
impl Solution {
    pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let hs: HashSet<i32> = nums.into_iter().collect();

        //let mut dummy = Box::new(ListNode::new(0));
        let mut dummy=Box::new(ListNode::new(0));
        //let mut tail = &mut dummy;
        let mut tail=&mut dummy;

        let mut cur=head;
        while let Some(mut node)=cur{
            cur=node.next.take();
            if !hs.contains(&node.val){
                tail.next=Some(node);
                tail=tail.next.as_mut().unwrap();
            }
        }
        dummy.next

        /*
        let mut cur = head;
        while let Some(mut node) = cur {
            cur = node.next.take();  // 取出下一個
            if !hs.contains(&node.val) {
                tail.next = Some(node);
                tail = tail.next.as_mut().unwrap();
            }
        }

        dummy.next
        */
    }
}
