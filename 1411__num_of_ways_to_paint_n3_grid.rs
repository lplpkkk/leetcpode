/*
impl Solution {
    pub fn num_of_ways(n: i32) -> i32 {
        //so when n is 1, it is 3*2^(3-1)
        //for the 2nd row, the 1st column will always have 2 choice
        //                 and the 2nd column depends
        //  a b
        //  b (a,c)

        // a b
        // c (a)

        //for the 3rd column, it maybe similar to the 1st column?    
    }
}
*/
impl Solution {
    pub fn num_of_ways(n: i32) -> i32 {
        let modulo = 1_000_000_007i64;

        // 初始化 n = 1 的情況
        // ABA (例如 121, 131...): 3色 * 2色 * 1色 = 6 種
        // ABC (例如 123, 132...): 3色 * 2色 * 1色 = 6 種
        let mut aba: i64 = 6;
        let mut abc: i64 = 6;

        // 從第 2 層開始算到第 n 層
        for _ in 1..n {
            // 為了避免在計算過程中被覆蓋，我們先把舊的值存起來，
            // 或者是直接計算出新的值。
            
            // 如果上一層是 ABA (3種延伸) + 如果上一層是 ABC (2種延伸)
            let next_aba = (aba * 3 + abc * 2) % modulo;
            
            // 如果上一層是 ABA (2種延伸) + 如果上一層是 ABC (2種延伸)
            let next_abc = (aba * 2 + abc * 2) % modulo;

            aba = next_aba;
            abc = next_abc;
        }

        // 答案是最後一層所有可能性的總和
        ((aba + abc) % modulo) as i32
    }
}
