impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        /*
        let mut ans=nums.dup();
        let len=nums.len();

        for i in 0..len{
            let idx=(i+nums[i]+len)%len;
            ans[i]=nums[idx];
        }
        ans
        */
        let n=nums.len() as i32;
        nums.iter().enumerate().map(|(i,&val)|{
            let idx=((i as i32+val)%n+n)%n;
            nums[idx as usize]
        })
        .collect()
    }
}
