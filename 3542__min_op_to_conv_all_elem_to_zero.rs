/*
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        let mut ans: i32 = 0;

        for v in nums {
            // pop all elements > v
            while let Some(&top) = stack.last() {
                if top > v {
                    stack.pop();
                } else {
                    break;
                }
            }
            // if v > 0 and top != v, we need a new operation for this value
            if v > 0 {
                if stack.last().copied() != Some(v) {
                    stack.push(v);
                    ans += 1;
                }
            }
            // if v == 0, we don't push; zeros naturally separate segments
        }

        ans
    }
}
*/

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut stack:Vec<i32>=Vec::new();
        let mut ans=0;

        for v in nums{
            while let Some(&top)=stack.last(){
                if top>v{
                    /* largest one is the only cared */
                    stack.pop();
                }else{
                    break;
                }
            }
            
            if v>0{
                if stack.last().copied()!=Some(v){
                    /* not equal, and larger, stands for a new layer */
                    stack.push(v);
                    ans+=1;
                }
            }

        }
        ans
        
    }
}
