impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n=strs.len();
        let m=strs[0].len();
        let s_b:Vec<&[u8]>=strs.iter().map(|s| s.as_bytes()).collect();

        let mut dp=vec![1;m];
        let mut max=1;

        for i in 0..m{
            for j in 0..i{
                let mut is_valid=true;
                for k in 0..n{
                    if s_b[k][j]>s_b[k][i]{
                        is_valid=false;
                    }
                }
                if is_valid{
                    dp[i]=dp[i].max(dp[j]+1);
                }
            }
            
            max=max.max(dp[i]);
        }   
        (m as i32)-max
    }

}
