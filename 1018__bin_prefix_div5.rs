/*
impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut ans=vec![0;nums.len()] as bool ;
        let mut tmp=0;
        for i in 0..nums.len(){
            tmp=tmp<<1+nums[i];
            if tmp%5==0{
                ans[i]=true;
            }        
        }
        ans
    }
}
*/
impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut ans=Vec::with_capacity(nums.len());
        let mut tmp=5;
        for num in nums{
            tmp=(tmp*2+num)%5;
            ans.push(tmp==0);
        }
        ans
    }
}
