impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let len=nums.len();
        let k=k as usize;
        let mut ans=i32::MAX;

        if len<2{
            return 0;
        }

        for i in 0..=len-k{
            let cur_diff=nums[i+k-1]-nums[i];
            ans=ans.min(cur_diff);
        }
        ans
    }
}
