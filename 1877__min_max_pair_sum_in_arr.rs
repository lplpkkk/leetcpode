impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        let len=nums.len();

        nums.sort_unstable();
        let mut ans=i32::MIN;

        for i in 0..len/2{
            let this_try=nums[i]+nums[len-1-i];
            ans=ans.max(this_try);
        }
        ans
    }
}
