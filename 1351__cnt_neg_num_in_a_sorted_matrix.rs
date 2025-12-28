impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let n=grid.len() as i32;
        let m=grid[0].len() as i32;

        let mut ans:i32=0;
        let mut row=n-1;
        let mut col=0;

        while row>=0 && col<m{
            if grid[row as usize][col as usize]<0{
                ans+= (m-col);
                row-=1;
            }else{
                col+=1;
            }
        }
        ans
    }
}
