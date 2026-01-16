/*
impl Solution {
    pub fn maximize_square_area(m: i32, n: i32, h_fences: Vec<i32>, v_fences: Vec<i32>) -> i32 {
        
    }
}
*/
use std::collections::HashSet;

impl Solution {
    pub fn maximize_square_area(m: i32, n: i32, mut h_fences: Vec<i32>, mut v_fences: Vec<i32>) -> i32 {
        // 1. 加入外邊界
        h_fences.push(1);
        h_fences.push(m);
        v_fences.push(1);
        v_fences.push(n);

        // 2. 排序以便後續處理
        h_fences.sort_unstable();
        v_fences.sort_unstable();

        // 3. 計算所有可能的水平間距並存入 HashSet
        let mut h_gaps = HashSet::new();
        let h_len = h_fences.len();
        for i in 0..h_len {
            for j in i + 1..h_len {
                h_gaps.insert(h_fences[j] - h_fences[i]);
            }
        }

        // 4. 計算垂直間距並找出最大的共同間距
        let mut max_side: i64 = -1;
        let v_len = v_fences.len();
        for i in 0..v_len {
            for j in i + 1..v_len {
                let gap = v_fences[j] - v_fences[i];
                if h_gaps.contains(&gap) {
                    max_side = max_side.max(gap as i64);
                }
            }
        }

        // 5. 處理回傳結果與取模
        if max_side == -1 {
            -1
        } else {
            let mod_val = 1_000_000_007;
            ((max_side * max_side) % mod_val) as i32
        }
    }
}
