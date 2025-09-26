impl Solution {
    pub fn triangle_number(nums: Vec<i32>) -> i32 {
        let mut ans:i32=0;
        let len=nums.len();

        if len<3{
            return 0;
        }

        let mut nums: Vec<i32>=nums;
        nums.sort();

        for k in (2..len).rev(){
            let mut max_val=nums[k];
            let mut l=0;
            let mut r=k-1;
            while l<r{
                if nums[l]+nums[r]>max_val{
                    //ok case
                    ans+=(r-l) as i32;
                    //find next;
                    r-=1;;
                }else{
                    //not ok case
                    l+=1;
                }
            }
        }
        ans
    }
}
