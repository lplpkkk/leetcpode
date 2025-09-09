impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        let n=n as usize;
        let delay=delay as usize;
        let forget=forget as usize;

        let mut dp=vec![0i64;n+1];
        let mut share=0i64;
        let MOD=1_000_000_007;
        dp[1]=1;

        for day in 2..=n{
            if day>=delay+1{
                //share+=dp[day-delay];
                share=(share+dp[day-delay]+MOD)%MOD;
            }
            
            if day>=forget+1{
                //share-=dp[day-forget];
                share=(share-dp[day-forget]+MOD)%MOD;
            }
            
            share%=MOD;
            dp[day]=share;
        }

        let mut ans=0i64;
        for day in n-forget+1..=n{
            ans+=dp[day];
            ans%=MOD
        }
        ans as i32
    }
}
