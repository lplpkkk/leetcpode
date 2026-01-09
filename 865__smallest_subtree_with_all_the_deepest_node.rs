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
    pub fn subtree_with_all_deepest(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(&root).1
    }

    fn dfs(node:&Option<Rc<RefCell<TreeNode>>>)->(i32,Option<Rc<RefCell<TreeNode>>>){
        if let Some(n)=node{
            let n_ref=n.borrow();

            let (left_depth,left_res)=Self::dfs(&n_ref.left);
            let (right_depth,right_res)=Self::dfs(&n_ref.right);

            if left_depth==right_depth{
                (left_depth+1,Some(Rc::clone(n)))
            }else if left_depth>right_depth{
                (left_depth+1,left_res)
            }else {
                (right_depth+1,right_res)
            }
        }else{
            (0,None)
        }
    }
    
}
