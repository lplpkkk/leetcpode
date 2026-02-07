impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut b_cnt=0;
        let mut ans=0;

        for c in s.chars(){
            if c=='b'{
                b_cnt+=1;
            }else{
                if b_cnt>0{
                    ans+=1;
                    b_cnt-=1;
                }
            }
        }
        ans
    }
}
