/*
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        // let dp[i][j] is the ans from transfer from word1[0..i] to word2[0..j]
        let word1_len=word1.len();
        let word2_len=word2.len();

        let arr1:Vec<char>=word1.chars().collect();
        let arr2:Vec<char>=word2.chars().collect();

        let mut dp=vec![vec![0;word2_len+1];word1_len+1];

        for i in 0..=word1_len{
            dp[i][0]=i;
        }
        for j in 0..=word2_len{
            dp[0][j]=j;
        }

        for i in 1..=word1_len{
            for j in 1..=word2_len{
                if arr1[i-1]==arr2[j-1]{
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    let insert=dp[i][j-1]+1;
                    let delete=dp[i-1][j]+1;
                    let replace=dp[i-1][j-1]+1;
                    dp[i][j]=insert.min(delete).min(replace);
                }
            }
        }
        dp[word1_len][word2_len] as i32
    }
}
*/
use std::cmp::min;
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (n,m) = (word1.len(), word2.len());
        let (w1,w2) = (word1.as_bytes(),word2.as_bytes());
        let (mut prev, mut next) = (vec![0;m+1],vec![0;m+1]);
        for i in 1..=m{
            prev[i] = i;
        }
        for i in 0..n{
            next[0] = i+1;
            for j in 0..m {
                next[j+1] = min(1 + prev[j+1],min(1 + next[j],if(w1[i] == w2[j]){ 0 }else{ 1 } + prev[j]));
            }
            std::mem::swap(&mut prev,&mut next);
        }
        return prev[m] as i32;
    }
}
