impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        fn contains_z(mut num:i32)->bool{
            while num>0{
                if num%10 ==0{
                    return true
                }else{
                    num/=10;
                }
            }
            false
        }

        for i in 1..n{
            let j=n-i;
            if !contains_z(i)&&!contains_z(j){
                return vec![i,j];
            }
        }
        vec![]
    }
}
