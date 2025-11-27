/*
impl Solution {
    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        // dp[i] stands for max value with remainder i
        let mut dp=vec![0;k];
        for num in nums{
            for i in 0..k{
                let new_remainder=(dp[i]+num)%k;
                dp[new_remainder]=dp[new_remainder].max(dp[i]+num);
            }
        }
        dp[0]
    }
}
*/
impl Solution {
    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        let k=k as usize;
        let mut min_prefix_sum=vec![i64::MAX;k];
        let mut max_sum=i64::MIN;
        let mut max_prefix=0;
        let mut cur_sum=0;

        min_prefix_sum[0]=0;

        for (i,&num) in nums.iter().enumerate(){
            cur_sum+=num as i64;
            let cur_remainder=(i+1)%k;
            if min_prefix_sum[cur_remainder]!=i64::MAX{
                max_sum=max_sum.max(cur_sum-min_prefix_sum[cur_remainder]);
            }

            if cur_sum<min_prefix_sum[cur_remainder]{
                min_prefix_sum[cur_remainder]=cur_sum;
            }
        }
        if max_sum==i64::MIN{
            return 0;
        }
        max_sum
    }
}
