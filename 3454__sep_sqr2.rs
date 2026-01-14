/*
impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        
    }
}
*/
use std::collections::{BTreeMap, HashMap};

impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let n = squares.len();
        
        // 1. 座標離散化 (Coordinate Compression) for X
        // 因為 x 座標很大，但正方形數量有限，我們只關心正方形的左右邊界
        let mut x_coords = Vec::new();
        for s in &squares {
            x_coords.push(s[0] as i64);
            x_coords.push((s[0] as i64) + (s[2] as i64));
        }
        x_coords.sort_unstable();
        x_coords.dedup();
        
        // 建立 x 到 index 的映射，方便線段樹使用
        let mut x_map = HashMap::new();
        for (i, &x) in x_coords.iter().enumerate() {
            x_map.insert(x, i);
        }
        
        let m = x_coords.len();
        if m == 0 { return 0.0; }

        // 2. 建立掃描線事件 (Events)
        // Tuple: (y, type, x_start_idx, x_end_idx)
        // type: 1 for bottom (add), -1 for top (remove)
        let mut events = Vec::new();
        for s in &squares {
            let x = s[0] as i64;
            let y = s[1] as i64;
            let l = s[2] as i64;
            
            let u_idx = *x_map.get(&x).unwrap();
            let v_idx = *x_map.get(&(x + l)).unwrap();
            
            events.push((y, 1, u_idx, v_idx));
            events.push((y + l, -1, u_idx, v_idx));
        }
        
        // 根據 y 排序，y 一樣時先處理加入(+1)再處理移除(-1)其實沒差，但在某些邊界case有好處
        events.sort_unstable_by(|a, b| a.0.cmp(&b.0));

        // 3. 初始化線段樹
        // count: 區間被覆蓋的次數
        // len: 區間被覆蓋的實際長度
        let mut count = vec![0; 4 * m]; 
        let mut len = vec![0.0; 4 * m];
        
        // 記錄每一層的資訊 (y, 這一層的高度, 這一層的有效寬度)
        let mut history: Vec<(f64, f64, f64)> = Vec::new(); // (y_bottom, height, valid_width)
        let mut total_area = 0.0;
        
        for i in 0..events.len() - 1 {
            let (y, type_, u, v) = events[i];
            
            // 更新線段樹
            update(1, 0, m - 1, u, v, type_, &mut count, &mut len, &x_coords);
            
            let next_y = events[i+1].0;
            if next_y > y {
                let h = (next_y - y) as f64;
                let w = len[1]; // root node 存著整體的有效覆蓋長度
                let area = w * h;
                total_area += area;
                history.push((y as f64, h, w));
            }
        }

        // 4. 尋找分割點
        let target = total_area / 2.0;
        let mut current_sum = 0.0;
        
        for (y_base, h, w) in history {
            if current_sum + (h * w) >= target {
                // 答案就在這一層
                if w == 0.0 { return y_base; } // 理論上不會發生，除非 target 是 0
                let needed = target - current_sum;
                return y_base + (needed / w);
            }
            current_sum += h * w;
        }

        -1.0
    }
}

// 線段樹 Update 函數
// node: 當前節點 index
// start, end: 當前節點管轄的 x_coords 範圍 [start, end]
// l, r: 這次修改的範圍 [l, r]
// val: +1 或 -1
fn update(
    node: usize, 
    start: usize, 
    end: usize, 
    l: usize, 
    r: usize, 
    val: i32, 
    count: &mut Vec<i32>, 
    len: &mut Vec<f64>, 
    x_coords: &Vec<i64>
) {
    // 區間不重疊
    if l >= end || r <= start {
        return;
    }
    
    // 完全包含
    if l <= start && end <= r {
        count[node] += val;
    } else {
        let mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val, count, len, x_coords);
        update(node * 2 + 1, mid, end, l, r, val, count, len, x_coords);
    }
    
    // 更新當前節點的 len
    if count[node] > 0 {
        // 如果這個節點被整個覆蓋，長度就是這個節點的物理寬度
        len[node] = (x_coords[end] - x_coords[start]) as f64;
    } else if end - start == 1 {
        // 葉子節點且 count == 0
        len[node] = 0.0;
    } else {
        // 非葉子節點，長度由子節點決定
        len[node] = len[node * 2] + len[node * 2 + 1];
    }
}
