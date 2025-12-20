impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let row_len=strs.len();//column len
        let col_len=strs[0].len();
        let mut ans=0;

        for i in 0..col_len{
            for j in 1..row_len{
                if strs[j].as_bytes()[i]<strs[j-1].as_bytes()[i]{
                    ans+=1;
                    break;
                }
            }
        }
        ans
        
    }
}
