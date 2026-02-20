impl Solution {
    pub fn make_largest_special(s: String) -> String {
        let mut res=Vec::new();
        let mut cnt=0;
        let mut i=0;

        let chars:Vec<char>=s.chars().collect();
        let n=chars.len();

        for j in 0..n{
            if chars[j]=='0'{
                cnt-=1;
            }else{
                cnt+=1;
            }

            if cnt==0{
                let inner_str:String=chars[i+1..j].iter().collect();
                let proc_str=Self::make_largest_special(inner_str);
                res.push(format!("1{}0",proc_str));
                i=j+1;
            }
        }

        res.sort_unstable_by(|a,b| b.cmp(a));
        res.concat()
    }
}
