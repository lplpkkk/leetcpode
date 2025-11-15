impl Solution {
    pub fn range_add_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = n as usize;
        // +1 to avoid boundary checks
        let mut diff = vec![vec![0; n + 1]; n + 1];

        for q in queries {
            let r1 = q[0] as usize;
            let c1 = q[1] as usize;
            let r2 = q[2] as usize;
            let c2 = q[3] as usize;

            diff[r1][c1] += 1;
            diff[r2 + 1][c1] -= 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        // Prefix sum over rows
        for r in 0..n {
            for c in 1..n {
                diff[r][c] += diff[r][c - 1];
            }
        }

        // Prefix sum over cols
        for c in 0..n {
            for r in 1..n {
                diff[r][c] += diff[r - 1][c];
            }
        }

        // Trim to n×n
        let mut ans = vec![vec![0; n]; n];
        for r in 0..n {
            for c in 0..n {
                ans[r][c] = diff[r][c];
            }
        }

        ans
    }
}
