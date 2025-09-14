use std::collections::HashSet;
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut row=HashSet::new();
        let mut col=HashSet::new();
        let row_len=matrix.len();
        if row_len==0{ return;}
        let col_len=matrix[0].len();

        for i in 0..row_len{
            for j in 0..col_len{
                if matrix[i][j] ==0{
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for i in 0..row_len{
            for j in 0..col_len{
                if row.contains(&i) || col.contains(&j){
                    matrix[i][j]=0;
                }
            }
        }
    }
}
