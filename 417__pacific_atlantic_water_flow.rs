impl Solution {
    fn dfs(
        h: &Vec<Vec<i32>>,
        visited: &mut Vec<Vec<bool>>,
        i: i32,
        j: i32,
        prev_h: i32,
    ) {
        let m = h.len() as i32;
        let n = h[0].len() as i32;

        // 越界或高度不符合或已訪問
        if i < 0 || j < 0 || i >= m || j >= n || visited[i as usize][j as usize] || h[i as usize][j as usize] < prev_h {
            return;
        }

        visited[i as usize][j as usize] = true;

        // 四個方向 DFS
        Self::dfs(h, visited, i + 1, j, h[i as usize][j as usize]);
        Self::dfs(h, visited, i - 1, j, h[i as usize][j as usize]);
        Self::dfs(h, visited, i, j + 1, h[i as usize][j as usize]);
        Self::dfs(h, visited, i, j - 1, h[i as usize][j as usize]);
    }

    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = heights.len();
        let n = heights[0].len();

        let mut pacific = vec![vec![false; n]; m];
        let mut atlantic = vec![vec![false; n]; m];

        // 太平洋邊界
        for i in 0..m {
            Self::dfs(&heights, &mut pacific, i as i32, 0, i32::MIN);
        }
        for j in 0..n {
            Self::dfs(&heights, &mut pacific, 0, j as i32, i32::MIN);
        }

        // 大西洋邊界
        for i in 0..m {
            Self::dfs(&heights, &mut atlantic, i as i32, (n - 1) as i32, i32::MIN);
        }
        for j in 0..n {
            Self::dfs(&heights, &mut atlantic, (m - 1) as i32, j as i32, i32::MIN);
        }

        // 收集同時可達的位置
        let mut ans = vec![];
        for i in 0..m {
            for j in 0..n {
                if pacific[i][j] && atlantic[i][j] {
                    ans.push(vec![i as i32, j as i32]);
                }
            }
        }

        ans
    }
}
