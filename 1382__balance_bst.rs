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
    pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut inorder=Vec::<i32>::new();
        Self::build_inorder(root,&mut inorder);
        Self::build_bst(&inorder, 0, (inorder.len()-1) as i32)
    }

    pub fn build_inorder(root: Option<Rc<RefCell<TreeNode>>>, inorder:&mut Vec<i32>){
        match root{
            Some(node)=>{
                let node=node.borrow();
                
                Self::build_inorder(node.left.clone(),inorder);
                inorder.push(node.val);
                Self::build_inorder(node.right.clone(),inorder);
            }
            None=>{
                return
            }
        }
    }

    pub fn build_bst(inorder:&Vec<i32>, start:i32, end:i32)->Option<Rc<RefCell<TreeNode>>>{
        if start>end{
            return None;
        }

        let mid=(start+end)/2;
        let l=Self::build_bst(inorder, start, mid-1);
        let r=Self::build_bst(inorder, mid+1, end);
        
        let node=TreeNode{
            val: inorder[mid as usize],
            left:l,
            right:r,
        };

        Some(Rc::new(RefCell::new(node)))
    }
}
