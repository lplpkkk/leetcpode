impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let mut y_minmax_by_x = vec![(i32::MAX, 0); n as usize + 1];
        let mut x_minmax_by_y = vec![(i32::MAX, 0); n as usize + 1];

        for b in &buildings {
            let &[x, y] = b.as_slice() else { panic!() };
            let (x_min, x_max) = x_minmax_by_y[y as usize];
            let (y_min, y_max) = y_minmax_by_x[x as usize];

            x_minmax_by_y[y as usize] = (x_min.min(x), x_max.max(x));
            y_minmax_by_x[x as usize] = (y_min.min(y), y_max.max(y));
        }

        let mut n_covered = 0;

        for b in buildings {
            let &[x, y] = b.as_slice() else { panic!() };
            let (x_min, x_max) = x_minmax_by_y[y as usize];
            let (y_min, y_max) = y_minmax_by_x[x as usize];

            if x_min < x && x < x_max && y_min < y && y < y_max {
                n_covered += 1;
            }
        }

        n_covered
    }
}
