/*impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let len=nums.len();
        let mut sign=0;//0-> inc, 1->dec
        let mut toggle_time=0;

        for i in 1..len{
            if sign==0{
                if nums[i]<nums[i-1]{
                    toggle_time+=1;
                    sign=1;
                    if toggle_time>2{
                        return false;
                    }
                    continue;
                }
            }else{
                if nums[i]>nums[i-1]{
                    toggle_time+=1;
                    sign=0;
                    if toggle_time>2{
                        return false;
                    }
                    continue;
                }
            }
        }
        if toggle_time==2{
            true
        }else{
            false
        }
        
    }
}*/
impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let len=nums.len();
        if len<4{
            return false;
        }
        let mut changes=0;
        let mut is_increasing:Option<bool>=None;

        for i in 1..len{
            if nums[i]==nums[i-1]{
                return false;
            }

            let cur_increasing=nums[i]>nums[i-1];

            match is_increasing{
                None=>{
                    if !cur_increasing{
                        return false;
                    }
                    is_increasing=Some(cur_increasing);
                }
                Some(last_trend)=>{
                    if cur_increasing!=last_trend{
                        changes+=1;
                        is_increasing=Some(cur_increasing);
                    }
                }
            }

            if changes>2{
                return false;
            }
            
        }
        changes==2
    }
}
