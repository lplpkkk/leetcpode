impl Solution {
    pub fn min_time(skill: Vec<i32>, mana: Vec<i32>) -> i64 {
        let n = skill.len();
        let m = mana.len();
        let mut times = vec![0i64; n];

        for &mj in &mana {
            let mut cur_time: i64 = 0;
            for i in 0..n {
                cur_time=(cur_time.max(times[i]))+(skill[i] as i64 * mj as i64);
            }
            times[n - 1] = cur_time;
            for i in (0..n - 1).rev() {
                times[i] = times[i + 1] - skill[i + 1] as i64 * mj as i64;
            }
            println!("{:?}\n",times[n-1]);
        }

        times[n - 1]
    }
}
