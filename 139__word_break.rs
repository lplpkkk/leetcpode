use std::collections::HashSet;

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let n=s.len();
        let s_bytes=s.as_bytes();
        let word_set:HashSet<&[u8]>=word_dict.iter().map(|w| w.as_bytes()).collect();
        let mut dp=vec![false;n+1];
        dp[0]=true;
        /* x _ x _ x 
           i
        */
        for i in 1..=n{
                /* x _ x _ x 
                   j ..i   
                */
            for j in 0..i{
                if dp[j] && word_set.contains(&s_bytes[j..i]){
                    dp[i]=true;
                    break;
                }
            }
        }
        dp[n]
    }
}
