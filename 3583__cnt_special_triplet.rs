/*
use std::collections::HashSet;
impl Solution {
    pub fn special_triplets(nums: Vec<i32>) -> i32 {
        let mut pass1=HashSet::new();
        let mut pass2=HashSet::new();
        let mut  ans=0;

        for num in nums{
            if pass1.contains(&num){
                if num&1==0 && pass2.contains( &(num/2)){
                    ans+=1;
                }
            }else{
                pass1.insert(num);
            }
        }
        ans
    }
}
*/
use std::collections::HashMap;

impl Solution {
    pub fn special_triplets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n < 3 {
            return 0;
        }
        let modulo: i64 = 1_000_000_007;
        let mut ans: i64 = 0;

        // 1. 预计算 TotalCounts: 存储每个值在整个数组中的总出现次数
        let mut total_counts: HashMap<i32, i64> = HashMap::new();
        for &num in nums.iter() {
            *total_counts.entry(num).or_insert(0) += 1;
        }

        // 2. PrefixCounts: 动态维护 nums[0] 到 nums[j-1] 中每个值的出现次数 (C_L)
        let mut prefix_counts: HashMap<i32, i64> = HashMap::new();

        // 3. 遍历中间索引 j (从 1 到 n - 2)
        for j in 1..=(n - 2) {
            let val_j = nums[j] as i64;
            let target = val_j * 2;
            
            // 每次迭代前，将 nums[j-1] 加入左侧计数 (C_L)
            if j > 0 {
                let prev_val = nums[j - 1];
                *prefix_counts.entry(prev_val).or_insert(0) += 1;
            }

            // ⚠️ 溢出检查
            if target > i32::MAX as i64 {
                continue;
            }
            let target_i32 = target as i32;

            // 检查目标值是否存在于数组中
            if let Some(&total_k_count) = total_counts.get(&target_i32) {
                // a) C_L (Left Count): target 在 nums[0..j-1] 中的出现次数
                let count_left = *prefix_counts.get(&target_i32).unwrap_or(&0);

                // b) C_R (Right Count): target 在 nums[j+1..n-1] 中的出现次数
                // C_R = Total_Count[target] - C_L[target] - (target 在 nums[j] 处的出现次数)
                
                // C_L[target] 包含了 nums[0]..nums[j-1] 的计数
                
                // total_counts[target] 包含所有索引的计数
                
                // 此时，需要知道 nums[j..n-1] 的计数，然后减去 nums[j] 处的计数
                // 我们可以使用 Total - Prefix - Current 这种方式
                
                // C_R 应该是 total_count 减去 (target 在 nums[0..j] 的出现次数)
                
                // 计算 target 在 nums[j] 处的出现次数 (0或1)
                let current_is_target: i64 = if nums[j] == target_i32 { 1 } else { 0 };

                // C_R = Total_Count[target] - C_L - (target 在 nums[j] 处的出现次数)
                let count_right = (total_k_count - count_left - current_is_target).max(0);


                // 4. 更新总数: C_L * C_R
                let contribution = (count_left * count_right) % modulo;
                ans = (ans + contribution) % modulo;
            }
        }

        ans as i32
    }
}
