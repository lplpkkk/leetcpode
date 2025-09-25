impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let len1=s1.len();
        let len2=s2.len();
        let len3=s3.len();
        if len1+len2 !=len3{
            return false;
        } 

        let s1_chars:Vec<char>=s1.chars().collect();
        let s2_chars:Vec<char>=s2.chars().collect();
        let s3_chars:Vec<char>=s3.chars().collect();
        
        let mut dp:Vec<Vec<bool>>=vec![vec![false;len2+1];len1+1];
        dp[0][0]=true;

        for i in 1..=len1{
            dp[i][0]=dp[i-1][0] && (s1_chars[i-1]==s3_chars[i-1]);
        }

        for j in 1..=len2{
            dp[0][j]=dp[0][j-1] && (s2_chars[j-1]==s3_chars[j-1]);
        }

        for i in 1..=len1{
            for j in 1..=len2{
                let match_s1=dp[i-1][j]&&(s1_chars[i-1]==s3_chars[i+j-1]);
                let match_s2=dp[i][j-1]&&(s2_chars[j-1]==s3_chars[i+j-1]);
                dp[i][j]=match_s1||match_s2;
            }
        }

        dp[len1][len2]

    }
}
