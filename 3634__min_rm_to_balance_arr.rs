/*
impl Solution {
    pub fn min_removal(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let n=nums.len();
        let mut ans=i32::MAX;

        if n<2{
            return 0;
        }

        for i in 0..n{
            let max_val=nums[n-1-i];
            let min_ac=max_val/k;
            let mut this_ans=i32::MAX;
            for j in 0..n{
                if nums[j]>=min_ac{
                    break;
                }else{
                    if this_ans==i32::MAX{
                        this_ans=1;
                    }else{
                        this_ans+=1;
                    }
                }
            }
            ans=ans.min(this_ans);
        }
        if ans==i32::MAX{
            0
        }else{
            ans
        }
    }
}
*/
impl Solution {
    pub fn min_removal(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let mut i = 0;
        let mut max_len = 0;
        let k_long = k as i64;
        
        for j in 0..nums.len() {
            while (nums[j] as i64) > (nums[i] as i64) * k_long {
                i += 1;
            }
            max_len = max_len.max(j - i + 1);
        }
        
        (nums.len() - max_len) as i32
    }
}
