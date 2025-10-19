/*
TLE:
use std::collections::HashSet;

impl Solution {
    pub fn max_distinct_elements(mut nums: Vec<i32>, k: i32) -> i32 {
        //let mut nums=nums.sort();
        let mut hs=HashSet::new();

        nums.sort_unstable();
        for &x in &nums{
            for j in -k..=k{
                let cand=x+j;
                if !hs.contains(&cand){
                    hs.insert(cand);
                    break;
                }        
            }
        }
        hs.len() as i32
    }
}
*/
impl Solution {
    pub fn max_distinct_elements(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let mut ans = 0;
        let mut last = i64::MIN; // 上一次選到的數字

        for &x in &nums {
            // 每個數能覆蓋區間 [x - k, x + k]
            let left = x as i64 - k as i64;
            let right = x as i64 + k as i64;

            // 避免跟前一個重疊
            let target = last + 1;
            if target <= right {
                // 取 max(left, last+1)，確保新選的數在可行範圍內且不同
                let choose = std::cmp::max(left, target);
                last = choose;
                ans += 1;
            }
        }

        ans
    }
}
