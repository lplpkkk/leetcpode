impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let n=n as usize;
        let mut ans=Vec::with_capacity(n);
        for i in 1..=(n/2){
            ans.push(i as i32);
            ans.push(-(i as i32));
        }
        if n % 2 == 1{
            ans.push(0);
        }
        ans
    }
}
