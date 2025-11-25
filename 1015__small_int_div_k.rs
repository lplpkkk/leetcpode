/*
impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        let cands=Vec[1,11,111,1111,11111];
        if (k&1)==0{
            return -1;
        }
        
        for i in 0..5{
            if (cands[i]%k)==0{
                return i;
            }
        }
        -1
    }
}
*/

impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        if k%2==0 || k%5==0{
            return -1;
        }
        let mut remainder=0;

        for len in 1..=k{
            remainder=(remainder*10+1)%k;
            if remainder==0{
                return len;
            }
        }
        -1
    }
}
