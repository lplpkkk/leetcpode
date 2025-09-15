impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let mut bitmask:u32=0;
        for i in broken_letters.chars(){
            bitmask|=1<<(i as u8 - b'a');
        }

        let mut cnt=0;
        for word in text.split_whitespace(){
            let mut can_type=true;
            for c in word.chars(){
                if (1<<(c as u8 -b'a')) &bitmask !=0{
                    can_type=false;
                    break;
                }
            }
            if can_type{
                cnt+=1;
            }
        }
        cnt
    }
}
