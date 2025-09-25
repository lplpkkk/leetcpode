impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if nums.is_empty(){
            return -1;
        }

        let mut l:usize=0;
        let mut r:usize=nums.len()-1;
        
        while l<=r{
            let mid:usize=l+(r-l)/2;
            if target==nums[mid]{
                return mid as i32;
            }    

            if(nums[l]<=nums[mid]){
                if nums[l]<=target && target<nums[mid]{
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if nums[mid]<target && target<=nums[r]{
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            
        }
        -1


    }
}
