/*impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let n=points.len();
        let mut max:f64=0.0;

        for i in 0..n{
            for j in (i+1)..n{
                for k in (j+1)..n{
                    let p1=&points[i];
                    let p2=&points[j];
                    let p3=&points[j];

                    let area = 0.5 * (
                        p1[0] * (p2[1] - p3[1]) +
                        p2[0] * (p3[1] - p1[1]) +
                        p3[0] * (p1[1] - p2[1])
                    ) as f64;

                    max=max.max(area.abs());
                }
            }
        }
        max
    }
}*/
impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let n = points.len();
        let mut max_area: f64 = 0.0; // Corrected: Explicit type f64

        for i in 0..n {
            for j in (i + 1)..n {
                for k in (j + 1)..n {
                    let p1 = &points[i];
                    let p2 = &points[j];
                    let p3 = &points[k];

                    let area = 0.5 * (
                        p1[0] * (p2[1] - p3[1]) +
                        p2[0] * (p3[1] - p1[1]) +
                        p3[0] * (p1[1] - p2[1])
                    ) as f64;
                    
                    max_area = max_area.max(area.abs());
                }
            }
        }
        max_area
    }
}
