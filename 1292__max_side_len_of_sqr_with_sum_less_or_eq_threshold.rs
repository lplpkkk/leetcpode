impl Solution {
    pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
        let m=mat.len();
        let n=mat[0].len();
        let mut p=vec![vec![0;n+1];m+1];

        for i in 0..m{
            for j in 0..n{
                p[i+1][j+1]=p[i][j+1]+p[i+1][j]-p[i][j]+mat[i][j];
            }
        }

        let mut left=0;
        let mut right=m.min(n);
        let mut ans=0;

        while left<=right{
            let mid=left+(right-left)/2;
            if mid==0{
                left=1;
                continue;
            }
            
            if Self::can_form_sqr(&p,m,n,mid,threshold){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        ans as i32
    }

    fn can_form_sqr(p: &Vec<Vec<i32>>,
    m:usize,
    n:usize,
    k:usize,
    thr:i32
    )->bool{
        for r in k..=m{
            for c in k..=n{
                let total=p[r][c]-p[r-k][c]-p[r][c-k]+p[r-k][c-k];
                if total<=thr{
                    return true;
                }
            }
        }
        false
    }
}
