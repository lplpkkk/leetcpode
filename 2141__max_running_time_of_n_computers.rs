impl Solution {
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        let n =n as i64;
        let num_bat=batteries.len();

        let total_sum:i64=batteries.iter().map(|&x| x as i64).sum();
        let mut low:i64=0;
        let mut high:i64=total_sum/n;
        let mut max_t:i64=0;
        while low<=high{
            let t=low+(high-low)/2;
            if Self::can_work(n,t,&batteries){
                max_t=t;
                low=t+1;
            }else{
                high=t-1;
            }
        }
        max_t
    }

    fn can_work(n: i64, t: i64, batteries: &Vec<i32>) -> bool {
        // 1. T=0 时，当然可以工作。
        if t == 0 {
            return true;
        }

        // 2. 计算所有电池的“有效电量”总和 (available_sum)。
        //    每块电池 b 最多只能贡献 t 分钟的电量。
        let available_sum: i64 = batteries.iter()
            .map(|&b| b as i64)
            .map(|b| b.min(t)) // 关键：每块电池对总供给的贡献上限是 t
            .sum();

        // 3. 总需求
        let required_sum = n * t;

        // 4. 判断有效电量是否足以满足总需求
        available_sum >= required_sum
    }
}
