impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let n=nums.len();
        let mut last_idx=-1 as i32;

        for i in 0..n{
            if nums[i]==1{
                if last_idx==-1{
                    last_idx=i as i32;
                }else{
                    if i as i32-last_idx<=k{
                        return false;
                    }
                }
                last_idx = i as i32;
            }
        }
        true
    }
}
