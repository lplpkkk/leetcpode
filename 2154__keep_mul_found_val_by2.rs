impl Solution {
    pub fn find_final_value(mut nums: Vec<i32>, mut original: i32) -> i32 {
        nums.sort_unstable();
        for num in nums{
            if num==original{
                original*=2;
            }
        }
        original
    }
}
