/*
impl Solution {
    pub fn avoid_flood(rains: Vec<i32>) -> Vec<i32> {
        
    }
}
*/


/*
use std::collections::{HashMap, BinaryHeap};

impl Solution {
    /// LeetCode 1488. 避免洪水泛滥
    pub fn avoid_flood(rains: Vec<i32>) -> Vec<i32> {
        let n = rains.len();
        // 1. 结果数组：rains[i] > 0 时为 -1，rains[i] == 0 时为要抽干的湖泊编号
        let mut ans = vec![-1; n]; 
        
        // 2. 存储每个湖泊上次下雨的日期索引 (lake_id -> day_index)
        let mut last_rain: HashMap<i32, i32> = HashMap::new();
        
        // 3. 存储所有晴天的日期索引（i），使用 BinaryHeap 模拟最小堆
        //    我们存储 -i，这样堆顶就是最小的 i (最早的晴天)
        let mut empty_days: BinaryHeap<i32> = BinaryHeap::new(); 

        for i in 0..n {
            let day = i as i32;
            let lake_id = rains[i];

            if lake_id > 0 {
                // Case 1: 下雨天 (lake_id > 0)
                
                // 检查是否会发生洪水
                if let Some(&last_day) = last_rain.get(&lake_id) {
                    // 湖泊 lake_id 已经满水，我们需要在 last_day 和 day 之间找到一个晴天抽干它。
                    
                    // 贪心策略：找到 last_day 之后，最早可用的晴天
                    // 注意：由于我们存储的是负数，我们要找一个比 -last_day 严格小的元素（即 i > last_day）
                    
                    // 目标：找到满足 empty_day_index > last_day 的最小 empty_day_index
                    // 在堆中，我们存储的是 -empty_day_index
                    
                    let mut found_dry_day: Option<i32> = None;
                    let mut temp_heap: BinaryHeap<i32> = BinaryHeap::new(); // 临时存储不合适的晴天
                    
                    while let Some(neg_dry_day) = empty_days.pop() {
                        let dry_day = -neg_dry_day; // 真实的晴天日期索引
                        
                        if dry_day > last_day {
                            // 找到了第一个满足条件（在上次下雨之后）的晴天
                            found_dry_day = Some(dry_day);
                            break;
                        } else {
                            // 这个晴天太早了（发生在上次下雨之前），暂时放回 temp_heap
                            temp_heap.push(neg_dry_day);
                        }
                    }
                    
                    // 将临时堆中的元素放回 primary heap
                    while let Some(neg_dry_day) = temp_heap.pop() {
                        empty_days.push(neg_dry_day);
                    }

                    if let Some(dry_day) = found_dry_day {
                        // 找到了可用的晴天，执行抽干操作
                        ans[dry_day as usize] = lake_id;
                        // 注意：我们不需要从 empty_days 中移除，因为已经在循环中 pop 出来了
                    } else {
                        // 没有找到 last_day 和 day 之间的晴天，无法避免洪水
                        return vec![];
                    }
                }
                
                // 更新该湖泊的上次降雨日期
                last_rain.insert(lake_id, day);

            } else {
                // Case 2: 晴天 (rains[i] == 0)
                
                // 将当前晴天的日期索引 (i) 记录到堆中。
                // 存入 -day，模拟最小堆，以便优先选择最早的晴天
                empty_days.push(-day);
                
                // 暂时将 ans[i] 设为 1（或任何大于 0 的湖泊编号）。
                // 实际抽干哪个湖，要在 Case 1 中确定。
                ans[i] = 1; 
            }
        }
        
        // 遍历结束后，所有 ans[i] == 1 的晴天都是“多余”的，保持 1 或 -1 都可以，
        // 但题目要求返回一个湖泊编号，所以保持为 1 (抽干湖泊 1) 是可以接受的。

        ans
    }
}

*/
use std::collections::{BTreeSet, HashMap};

impl Solution {
    pub fn avoid_flood(rains: Vec<i32>) -> Vec<i32> {
        let mut lakes  = HashMap::new();
        let mut days   = BTreeSet::new();
        let mut result = Vec::with_capacity(rains.len());

        for (today, lake) in rains.into_iter().enumerate() {
            if lake == 0 {
                days.insert(today);
                result.push(1);
            } else {
                if let Some(filled) = lakes.insert(lake, today) {
                    if let Some(&day) = days.range(filled..).next() {
                        result[day] = lake;
                        days.remove(&day);
                    } else {
                        return Vec::default();
                    }
                }
                result.push(-1);
            }
        }
        result
    }
}
