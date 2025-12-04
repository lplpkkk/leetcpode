/*impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        
    }
}
*/
impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let chars: Vec<char> = directions.chars().collect();
        let n = chars.len();
        
        // 1. 找到左邊界：第一個「不是 L」的位置
        let mut start = 0;
        while start < n && chars[start] == 'L' {
            start += 1;
        }
        
        // 如果全是 L (例如 "LLL")，直接回傳 0
        if start == n {
            return 0;
        }

        // 2. 找到右邊界：從右往左找第一個「不是 R」的位置
        let mut end = n - 1;
        while end > start && chars[end] == 'R' {
            end -= 1;
        }
        
        // 3. 再次檢查邊界 (針對 "LLRR" 或 "R" 這種情況)
        // 如果縮減完後，end 停留在 start，而且這個位置也是 R，代表剩下的全是 R (如 "LLRR")
        // 這種情況也是 0
        if start == end && chars[start] == 'R' {
            return 0;
        }

        // 4. 計算中間範圍的撞擊數
        // 在 [start, end] 區間內，所有的 L 和 R 最終都會撞成 S
        let mut count = 0;
        for i in start..=end {
            if chars[i] != 'S' {
                count += 1;
            }
        }
        
        count
    }
}
