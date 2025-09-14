use std::collections::HashSet;

/*
/* only beats 47%*/
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut set:HashSet<i32>=HashSet::new();
        for &i in &nums{
            if set.contains(&i){
                return true;
            }else{
                set.insert(i);
            }
        }
        false
    }
}
*/
/* this beats 88% */
impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort_unstable();
        for i in 1..nums.len(){
            if nums[i]==nums[i-1]{
                return true;
            }
        }
        false
    }
}

