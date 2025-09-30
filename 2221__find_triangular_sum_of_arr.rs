impl Solution {
    pub fn triangular_sum(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            nums[0]
        } else {
            Self::triangular_sum(
                nums.windows(2)
                    .map(|w: &[i32]| w.iter().sum::<i32>() % 10)
                    .collect()
            )
        }
    }
}
