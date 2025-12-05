/*
impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        let mut t1=nums.iter().collect().sum();
        let mut t2=0;
        let mut ans=0;
        for i in 0..nums.len(){
            if t1&1==t2&1{
                ans+=1;
            }
            t1+=nums[i];
            t2-=nums[i];
        }
        ans
    }
}
*/
impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        // 1. 计算整个数组的总和。使用 i64 避免编译错误和潜在溢出。
        let total_sum: i64 = nums.iter()
                                 .map(|&x| x as i64)
                                 .sum();
        
        // 2. 检查总和的奇偶性（TotalSum % 2 == 0 吗？）
        // 如果 TotalSum 是奇数，则 0 = 1 不成立，答案永远是 0。
        if total_sum % 2 != 0 {
            return 0;
        }

        // 3. 如果 TotalSum 是偶数，则任何分割点都满足条件。
        // 分割点 i 的有效范围是 0 <= i < n - 1。
        // 如果 n < 2，则没有有效的非空分割。
        if n < 2 {
            return 0;
        }

        // 总的分割点数量是 n - 1。
        (n - 1) as i32
    }
}
