use std::collections::HashMap;
/*
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let mut hm=HashMap::new();
        let n=nums.len();
        
        for num in nums{
            if hm.contains(&num){
                hm[num]++;
                if hm[num]==n/2+1{
                    return num;
                }
            }else{
                hm.new()
            }
        }
        0 // not expected to reach here
    }
}
*/
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let mut hm=HashMap::new();
        
        for num in nums{
            if hm.contains_key(&num){
                return num;
            }else{
                hm.insert(num,1);
            }
        }
        0
    }
}
