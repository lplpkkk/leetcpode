impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let mut ones=0;
        let mut ans=0;
        let str=s.as_bytes();

        for i in 0..str.len(){
            if str[i]==b'1'{
                ones+=1;
            }else if i>0 && str[i-1]==b'1'{
                ans+=ones;
            } 
        }
        ans    

    }
}
