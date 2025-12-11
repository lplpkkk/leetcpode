/*
impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        //use a for loop to setup tmp_arr[i][j]
        //tmp_arr[i][j], where the element is less than complexity[i]
        //sum up the permutation of tmp[i]
    }
}
*/
impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = complexity.len();
        let first = complexity[0];

        for &x in &complexity[1..] {
            if x <= first {
                return 0;
            }
        }

        let mut fact: i64 = 1;
        for i in 2..n as i64 {
            fact = (fact * i) % MOD;
        }

        fact as i32
    }
}
