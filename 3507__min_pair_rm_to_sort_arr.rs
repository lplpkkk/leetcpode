impl Solution {
    pub fn minimum_pair_removal(nums: Vec<i32>) -> i32 {
        let mut ops=0;
        let mut nums=nums;

        while !Self::is_sorted(&nums){
            ops+=1;

            let mut min_sum=i32::MAX;
            let mut min_idx=0;

            for i in 0..nums.len()-1{
                let sum=nums[i]+nums[i+1];

                if sum<min_sum{
                    min_sum=sum;
                    min_idx=i;
                }
            }

            nums[min_idx]=min_sum;
            nums.remove(min_idx+1);
        }
        ops
    }

    fn is_sorted(nums:&Vec<i32>)->bool{
        for i in 0..nums.len()-1{
            if nums[i]>nums[i+1]{
                return false;
            }
        }
        true
    }
}
