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
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>)->i32{
            match root{
                Some(root)=>{
                    let l=dfs(root.borrow().left.clone());
                    let r=dfs(root.borrow().right.clone());
                    if (l-r).abs()>1||l==-1||r==-1{
                        return -1;
                    }
                    l.max(r)+1
                }
                None=>0
            }
        }
        dfs(root)!=-1
    }
}
