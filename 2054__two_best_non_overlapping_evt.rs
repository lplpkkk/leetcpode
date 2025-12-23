impl Solution {
    pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
        let mut events=events;
        events.sort_unstable_by_key(|e| e[0]);
        let n=events.len();
        let mut suffix_max=vec![0;n+1];

        for i in (0..n).rev(){
            suffix_max[i]=suffix_max[i+1].max(events[i][2]);
        }

        let mut ans=0;
        for i in 0..n{
            let cur_val=events[i][2];
            let end_time=events[i][1];

            let idx=events.partition_point(|e| e[0]<=end_time);
            let mut cand=cur_val+if idx<n{ suffix_max[idx]}else{ 0};
            ans=ans.max(cand);
        }
        ans
    }
}
