impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums.into_iter().map(|x| {
            if x%2==0{
                -1
            }else{
                //find the msb:
                let k=x.trailing_ones();
                x-(1<<(k-1))
            }
        }).collect()
    }
 /*   
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        let mut ans=vec![-1;nums.len()];

        for i in 0..nums.len(){
            if nums[i]%2==0{
                continue;
            }
            for j in 0..nums[i]{
                if (j|(j+1))==nums[i]{
                    ans[i]=j;
                    break;
                }
            }
        }
        ans
    }
    */
}
