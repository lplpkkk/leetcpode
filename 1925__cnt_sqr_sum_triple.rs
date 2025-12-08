use std::collections::HashSet;
impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut hs=HashSet::new();
        let mut ans=0;
        for cand in 1..=n{
            hs.insert(cand*cand);
        }
        for i in 5..=n{
            for j in 1..=(i-1){
                let last=(i*i-j*j);
                if last>0 && hs.contains(&last){
                    ans+=1;
                }
            }
        }
        ans
    }

}
