/*
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>, k: i32, dist: i32) -> i64 {
        
    }
}
*/
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>, k: i32, dist: i32) -> i64 {
        let n=nums.len();
        let target_k=(k-1) as usize;
        let dist=dist as usize;

        let mut sorted_unique=nums.clone();
        sorted_unique.sort_unstable();
        sorted_unique.dedup();
        let m=sorted_unique.len();

        let mut bit_sum=vec![0i64;m+1];
        let mut bit_cnt=vec![0i32;m+1];

        let mut update=|rank:usize, val:i32, delta:i32, b_sum:&mut Vec<i64>, b_cnt:&mut Vec<i32>|{
            let mut i=rank;
            while i<=m{
                b_sum[i]+=(val as i64)* (delta as i64);
                b_cnt[i]+=delta;
                i+=i&(!i+1);
            }
        };

        let mut max_pow2=1;
        while (max_pow2<<1)<=m{
            max_pow2<<=1;
        }

        let mut min_extra_cost=i64::MAX;
        for i in 1..n{
            let rank=sorted_unique.binary_search(&nums[i]).unwrap()+1;
            update(rank,nums[i],1,&mut bit_sum, &mut bit_cnt);
            
            if i>dist+1{
                let old_val=nums[i-dist-1];
                let old_rank=sorted_unique.binary_search(&old_val).unwrap()+1;
                update(old_rank,old_val,-1, &mut bit_sum, &mut bit_cnt);
            }

            if i>=target_k{
                let mut idx=0;
                let mut cc=0;
                let mut cs=0i64;
                let mut p=max_pow2;
                
                while p>0{
                    let next_idx=idx+p;
                    if next_idx<=m&&(cc+bit_cnt[next_idx])<target_k as i32{
                        idx=next_idx;
                        cc+=bit_cnt[idx];
                        cs+=bit_sum[idx];
                    }
                    p>>=1;
                }
                if cc<target_k as i32{
                    cs+=(target_k as i32-cc) as i64* sorted_unique[idx] as i64;
                }
                min_extra_cost=min_extra_cost.min(cs);
            }
        }
        nums[0] as i64 + min_extra_cost
    }

}
