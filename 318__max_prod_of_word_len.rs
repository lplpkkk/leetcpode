impl Solution {
    pub fn comp(s:&str)->u32{
        let mut v:u32=0;

        for byte in s.bytes(){
            let idx=(byte-b'a') as u32;
            v|=(1<<idx);
        }
        v
    }

    pub fn max_product(words: Vec<String>) -> i32 {
        let len=words.len();
        let mut max=0;
        let mut codes:Vec<u32>=Vec::with_capacity(len);
        let mut lengths:Vec<i32>=Vec::with_capacity(len);

        for word in words.iter(){
            codes.push(Self::comp(word.as_str()));
            lengths.push(word.len()as i32);
        }
        
        for i in 0..len{
            for j in (i+1)..len{
                if (codes[i]&codes[j])==0{
                    let prod=lengths[i]*lengths[j];
                    if prod>max{
                        max=prod;
                    }
                }
            }
        }
        max
    }
}
