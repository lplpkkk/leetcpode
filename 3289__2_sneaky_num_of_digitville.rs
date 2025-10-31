use std::collections::HashSet;
impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut hs=HashSet::new();
        let mut ans=Vec::new();

        for num in nums{
            if !hs.contains(&num){
                hs.insert(num);
            }else{
                ans.push(num);
            }
        }
        ans
    }
}
