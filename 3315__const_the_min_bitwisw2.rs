impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums.into_iter().map(|x| {
            if x%2==0{
                -1
            }else{
                let k=x.trailing_ones();
                x-(1<<(k-1))
            }
        }).collect()
    }
}
