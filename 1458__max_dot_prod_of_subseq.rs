use std::cmp;

impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let n=nums1.len();
        let m=nums2.len();

        let mut dp=vec![vec![i32::MIN;m];n];
        
        for i in 0..n{
            for j in 0..m{
                let cur_prod=nums1[i]*nums2[j];
                let mut max_val=cur_prod;

                if i>0&&j>0{
                    max_val=max_val.max(cur_prod+dp[i-1][j-1]);
                }

                if i>0{
                    max_val=max_val.max(dp[i-1][j]);
                }

                if j>0{
                    max_val=max_val.max(dp[i][j-1]);
                }

                dp[i][j]=max_val;
            }
        }
        dp[n-1][m-1]
    }
}
