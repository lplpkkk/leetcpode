impl Solution {
    pub fn maximum_happiness_sum(happiness: Vec<i32>, k: i32) -> i64 {
        let mut happiness=happiness;
        happiness.sort_unstable_by(|a,b| b.cmp(a));
        let mut ans=0;

        let k_usize = k as usize;

        for i in 0..k_usize{
            let cur_val=(happiness[i] as i64 -i as i64).max(0);
            ans+=cur_val;
        }
        ans
    }
}
