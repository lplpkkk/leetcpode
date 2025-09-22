
use std::collections::HashSet;
impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {

        let n=nums.len();
        if n<4{
            return Vec::new();
        }

        let mut ans:HashSet<Vec<i32>>=HashSet::new();
        //let mut ans=Vec::new();
        let mut nums = nums;
        nums.sort_unstable();
        
        for i in 0..n-3{
            if i>0&&nums[i]==nums[i-1]{
                continue;
            }
            for j in (i+1)..nums.len()-2{
                if j>(i+1)&& nums[j]==nums[j-1]{
                    continue;
                }
                let mut l=j+1;
                let mut r=n-1;
                while l<r{
                    let sum=(nums[i] as i64)
                        + (nums[j] as i64) 
                        + (nums[l] as i64)
                        + (nums[r] as i64);
                    if sum==target as i64 {
                        let mut tmp=vec![nums[i],nums[j],nums[l],nums[r]];
                        tmp.sort_unstable();
                        ans.insert(tmp);

                        l+=1;
                        r-=1;

                    }else if sum<target as i64{
                        l+=1;
                    }else{
                        r-=1;
                    }
                }
            }
        }
        ans.into_iter().collect()
    }
}
