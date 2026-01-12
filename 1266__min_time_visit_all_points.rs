impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let len=points.len();
        let mut ans=0;

        for i in 1..len{
            let mut x=points[i][0]-points[i-1][0];
            let mut y=points[i][1]-points[i-1][1];
            let larger=x.abs().max(y.abs());

            ans+=larger;
        }
        ans
    }
}
