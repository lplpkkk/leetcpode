/* TLE solution 
impl Solution {
    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let len=energy.len();
        let mut ans=i32::MIN;
        for i in 0..len{
            let mut this_idx=i;
            let mut this_ans=0;

            while this_idx<len{
                this_ans+=energy[this_idx];
                this_idx+=k as usize;
            }
            ans=ans.max(this_ans);
        }
        ans
    }
}
*/

impl Solution {
    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let len=energy.len();
        let mut ans=i32::MIN;
        let mut dp=vec![0;len];

        for i in (0..len).rev(){
            dp[i]=energy[i];
            let k = k as usize;
            if i+k<len{
                dp[i]+=dp[i+k];
            }
            ans=ans.max(dp[i]);
        }
        ans
    
    }
}
