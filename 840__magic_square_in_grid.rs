/*
impl Solution {
    pub fn is_magic(sub: &Vec<Vec<i32>>)->bool{
        let m=sub[0].len();
        let n=sub.len();
        if m<3||n<3{
            return false;
        }
        if sub[1][1]!=5{
            return false;
        }

        let mut chk_mask=0;
        /* check row */
        for j in 0..3{
            let mut sum=0;
            for i in 0..3{
                if sub[i][j]==0||sub[i][j]>9{
                    return false;
                }
                chk_mask|=(1<<sub[i][j]);

                sum+=sub[j][i];
            }
            if sum!=15{
                return false;
            }
        }

        if chk_mask!=((1<<10)-1){
            return false;
        }

        /* check col */
        for i in 0..3{
            let mut sum=0;
            for j in 0..3{
                sum+=sub[j][i];
            }
            if sum!=15{
                return false;
            }
        }

        if sub[0][0]+sub[2][2]!=10{
            return false;
        }

        if sub[0][2]+sub[2][0]!=10{
            return false;
        }

        true

    }

    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let m=grid[0].len();
        let n=grid.len();

        if m<3||n<3{
            return 0;
        }

        let mut ans=0;
        for j in 0..n-3{
            for i in 0..m-3{
                if is_magic(&grid[i][j])==true{
                    ans+=1;
                }
            }
        }
        ans
    }
}
*/
/*
impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        
    }
}
*/
impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        if rows < 3 || cols < 3 { return 0; }

        let mut ans = 0;
        // 使用 0..=rows-3 包含最後一個可能的起點
        for r in 0..=rows - 3 {
            for c in 0..=cols - 3 {
                if Self::is_magic(&grid, r, c) {
                    ans += 1;
                }
            }
        }
        ans
    }

    fn is_magic(grid: &Vec<Vec<i32>>, r: usize, c: usize) -> bool {
        // 1. 快速剪枝：中心點必須是 5
        if grid[r + 1][c + 1] != 5 {
            return false;
        }

        // 2. 檢查 1-9 出現情況與 Row Sum
        let mut mask = 0;
        for i in 0..3 {
            let mut row_sum = 0;
            for j in 0..3 {
                let val = grid[r + i][c + j];
                if val < 1 || val > 9 { return false; }
                mask |= 1 << val;
                row_sum += val;
            }
            if row_sum != 15 { return false; }
        }

        // 檢查是否剛好是 1~9 (bit 1 到 bit 9 都要是 1)
        if mask != 0x3FE { return false; }

        // 3. 檢查 Column Sum
        for j in 0..3 {
            let col_sum = grid[r][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j];
            if col_sum != 15 { return false; }
        }

        // 4. 檢查對角線 (Diagonal)
        // 因為中心已經是 5，且行列皆為 15，只要對角線兩頭加起來是 10 即可
        if grid[r][c] + grid[r + 2][c + 2] != 10 || 
           grid[r][c + 2] + grid[r + 2][c] != 10 {
            return false;
        }

        true
    }
}
