impl Solution {
    pub fn largest_square_area(bottom_left: Vec<Vec<i32>>, top_right: Vec<Vec<i32>>) -> i64 {
        let n=bottom_left.len();
        let mut max_s:i64=0;

        for i in 0..n{
            for j in i+1..n{
                let mut x1=bottom_left[i][0].max(bottom_left[j][0]);
                let mut y1=bottom_left[i][1].max(bottom_left[j][1]);
                let mut x2=top_right[i][0].min(top_right[j][0]);
                let mut y2=top_right[i][1].min(top_right[j][1]);
                
                if x2>x1 && y2>y1{
                    let w=(x2-x1) as i64;
                    let h=(y2-y1) as i64;

                    let side=w.min(h) ;
                    max_s=max_s.max(side);
                }
            }
        }
        max_s*max_s

    }
}
