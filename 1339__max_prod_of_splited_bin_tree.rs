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
impl Solution {
    pub fn max_product(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut q=Vec::new();
        fn get_sum(node:&Option<Rc<RefCell<TreeNode>>>, q:&mut Vec<i64>)->i64{
            match node{
                Some(n)=>{
                    let n=n.borrow();
                    let left_sum=get_sum(&n.left,q);
                    let right_sum=get_sum(&n.right,q);
                    let cur_val=n.val as i64+left_sum+right_sum;
                    q.push(cur_val);
                    cur_val
                }
                None=>0,
            }
        }
        let total_sum=get_sum(&root,&mut q);
        let mut max_prod=i64::MIN;

        for s in q{
            let mut this_prod=(s*(total_sum-s))as i64;
            max_prod=max_prod.max(this_prod);
        }
        (max_prod%1_000_000_007) as i32 
    }
}
