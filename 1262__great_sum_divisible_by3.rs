/*
impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let mut nums_s=nums;    
        nums_s.sort_unstable();
        let mut sum=nums.sum();

        if sum%3==0{
            return sum;
        }

        let len=nums.len();
        
        //try to remove 1..n element
        for i in 0..(1<<len){
            let mut tmp_sum=sum;
            for j in 0..len{
                if nums_s&(1<<j){
                    sum-=nums[j];
                }
            }
            if sum%3==0{
                return sum;
            }
        }
        0 
    }
}

*/
impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        //use dp to solve
        let mut dp=vec![0,-1,-1];

        for n in nums{
            let mut next_dp=dp.clone();
            let remainder=(n%3) as usize;

            for i in 0..3{
                if dp[i]==-1{
                    continue;
                }
                let new_remainder= (i+remainder)%3 ;
                let new_sum=dp[i]+n;
                next_dp[new_remainder]=next_dp[new_remainder].max(new_sum);
            }
            dp=next_dp;
        }
        dp[0]
    }
}
