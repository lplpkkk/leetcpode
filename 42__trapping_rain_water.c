impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n=height.len();
        if n==0{
            return 0;
        }

        let mut l:usize=0;
        let mut r:usize=n-1;
        let mut ans=0;
        let mut left_max=0;
        let mut right_max=0;

        while l<r{
            if height[l]<height[r]{
                if height[l]>=left_max{
                    left_max=height[l];
                }else{
                    ans=ans+(left_max-height[l]);
                }
                l+=1;
            }else{
                if height[r]>=right_max{
                    right_max=height[r];
                }else{
                    ans=ans+(right_max-height[r]);
                }

                if r==0{
                    break;
                }
                r-=1;
            }
        }       
        ans
    }
}
