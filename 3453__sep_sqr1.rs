
/*
impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let len=squares.len();
        let max_y=0;
        
        for i in 0..len{
            max_y=max_y.max(squares[i][1]+squares[i][2]);
        }

        for i in 0..max_y{
            let mut below=0;
            let mut above=0;

            for j in 0..len{
                //sumup below 
                let mut h=if i>squares[i][1]{
                    i-square[i][1]
                }else{
                    squares[i][2]
                }
                below+=(h*squares[i][2]);
                
                //sumup above
                let mut h2=if i>(squares[i][1]+squares[i][2]){
                    0
                }else{
                    squars[i][1]+squars[i][2]-i
                }
                above+=(h2*squars[i][2]);
            }
            if below==above{
                return i;
            }
        }
        -1
    }
}
*/
impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        // 1. 計算總面積並找出 y 的搜尋範圍
        let mut total_area: f64 = 0.0;
        let mut min_y = f64::MAX;
        let mut max_y = f64::MIN;

        for sq in &squares {
            let y = sq[1] as f64;
            let l = sq[2] as f64; // 題目是正方形，邊長 l
            total_area += l * l;
            
            min_y = min_y.min(y);
            max_y = max_y.max(y + l);
        }

        let target = total_area / 2.0;
        
        // 2. 二分搜尋 (Binary Search)
        let mut left = min_y;
        let mut right = max_y;
        
        // 跑 100 次足夠讓精度達到 10^-5 以上，比檢查 diff < 1e-5 更快且穩定
        for _ in 0..100 {
            let mid = left + (right - left) / 2.0;
            
            if Self::get_area_below(&squares, mid) < target {
                left = mid;
            } else {
                right = mid;
            }
        }

        left // 回傳近似值
    }

    // 輔助函式：計算 y = line 這條線下方的總面積
    fn get_area_below(squares: &Vec<Vec<i32>>, line: f64) -> f64 {
        let mut current_area = 0.0;
        for sq in squares {
            let y = sq[1] as f64;
            let l = sq[2] as f64;
            let top = y + l;

            if line <= y {
                // 線在正方形下方，貢獻面積 0
                current_area += 0.0;
            } else if line >= top {
                // 線在正方形上方，貢獻整個正方形面積
                current_area += l * l;
            } else {
                // 線切過正方形，計算下半部面積 (寬 * 高)
                // 高度 = 線的位置 - 正方形底部
                current_area += l * (line - y);
            }
        }
        current_area
    }
}
