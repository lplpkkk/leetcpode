/*impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        
    }
}
*/
impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        points
            .into_iter()
            .fold(std::collections::HashMap::new(), |mut map, p| {
                *map.entry(p[1]).or_insert(0_usize) += 1;
                map
            })
            .into_values()
            .filter(|&v| v > 1)
            .map(|v| v * (v - 1) >> 1)
            .fold((0, 0), |(r, s), l| ((r + l * s) % 1000000007, s + l))
            .0 as _
    }
}
