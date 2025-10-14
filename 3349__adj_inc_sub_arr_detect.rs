/*
impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        let len=nums.len();
        let mut cnt=0;
        let k=k as usize;
        let mut fail=0;

        
        for i in 0..len-k{
            fail=0;
            for j in i..=i+k-1{
                println!(" [{}] {}..{}",i,nums[j],nums[j+1]);
                if nums[j]>=nums[j+1]{
                    fail=1;
                    break;
                }
            }

            if fail==0{
                cnt+=1;
                println!("{}",i);
            }
            
        }
        if cnt>=2{
            return true
        }
        false
    }
}
*/
impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        nums.windows(2)
            // we store the lengths of the last two strictly increasing subarrs.
            // the windows method eats the first elem, 
            // so we start having already considered it.
            .scan((0, 1), |mut acc, pair| {
                if pair[0] < pair[1] {
                    acc.1 += 1;
                } else {
                    *acc = (acc.1, 1);
                }
                Some((acc.0 >= k && acc.1 >= k) || acc.1 >= 2 * k)
            })
            .any(|check| check)
    }
}
