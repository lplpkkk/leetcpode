/*
impl Solution {
    pub fn largest_magic_square(grid: Vec<Vec<i32>>) -> i32 {
        let m=grid.len();
        let n=grid[0].len();
        let mut ans=0;

        for i in 0..m{
            for j in 0..n{
                ans=ans.max(get_ans_from_left_top(grid[i][j],m-i,n-j));        
            }
        }
        ans
    }

    pub fn get_ans_from_left_top(this_node:Vec<Vec<i32>>, x_lim:i32, y_lim:i32)->i32{

    }
}
*/
impl Solution {
    pub fn largest_magic_square(grid: Vec<Vec<i32>>) -> i32 {
        let m=grid.len();
        let n=grid[0].len();
        let mut r_prefix=vec![vec![0;n+1];m];
        let mut c_prefix=vec![vec![0;n];m+1];

        for i in 0..m{
            for j in 0..n{
                r_prefix[i][j+1]=r_prefix[i][j]+grid[i][j];
                c_prefix[i+1][j]=c_prefix[i][j]+grid[i][j];
            }
        }

        let mut ans=1;

        for i in 0..m{
            for j in 0..n{
                let max_len=(m-i).min(n-j);
                if max_len as i32<=ans{ continue;}
                
                for k in (ans as usize +1..=max_len).rev(){
                    if Self::is_magic(&grid,&r_prefix,&c_prefix,i,j,k){
                        ans=k as i32;
                        break;
                    }
                }
            }
        }
        ans
    }

    fn is_magic(
        grid: &Vec<Vec<i32>>,
        r_pre: &Vec<Vec<i32>>,
        c_pre: &Vec<Vec<i32>>,
        r:usize, c:usize, k:usize
    )->bool{
        let target=r_pre[r][c+k]-r_pre[r][c];

        for i in 0..k{
            let r_sum=r_pre[r+i][c+k]-r_pre[r+i][c];
            if r_sum!=target{ return false};
        }

        for i in 0..k{
            let c_sum=c_pre[r+k][c+i]-c_pre[r][c+i];
            if c_sum!=target{ return false};
        }

        let mut d1=0;
        let mut d2=0;

        for i in 0..k{
            d1+=grid[r+i][c+i];
            d2+=grid[r+i][c+k-1-i];
        }

        if d1!=target||d2!=target{
            return false;
        }
        
        true
    }
}
