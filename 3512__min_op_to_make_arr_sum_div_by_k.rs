impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans=0;
        for num in nums{
            ans+=(num%k);
            ans%=k;
        }
        ans
    }
}
