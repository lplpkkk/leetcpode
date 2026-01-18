impl Solution {
    pub fn num_sub(s: String) -> i32 {
        let modulo=1_000_000_007;
        let mut ans:i64=0;
        let mut cnt:i64=0;

        for c in s.chars(){
            if c=='1'{
                cnt+=1;
                ans=(ans+cnt)%modulo;
            }else{
                cnt=0;
            }
        }
        ans as i32
    }
}
