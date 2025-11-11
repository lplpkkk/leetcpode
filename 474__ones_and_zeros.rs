/*
impl Solution {
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32 {
        
    }
}
*/

impl Solution {
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32 {
        let mut dp=vec![vec![0;(n+1)as usize];(m+1) as usize];
        for s in strs{
            let zeros=s.bytes().filter(|&b| b==b'0').count() as i32;
            let ones=s.len() as i32-zeros ;

            for i in (zeros..=m).rev(){
                for j in (ones..=n).rev(){
                    /* how many 0s or 1s can be filled */
                    dp[i as usize][j as usize]=dp[i as usize][j as usize].max(dp[(i-zeros) as usize][(j-ones) as usize]+1);
                }
            }
        }
        dp[m as usize][n as usize]
    }
}
