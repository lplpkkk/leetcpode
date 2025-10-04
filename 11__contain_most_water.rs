
/*
impl Solution {
    pub fn get_area(h:&Vec<i32>, l:usize,r:usize) ->i32 {
        let len:i32=(r-l) as i32;
        h[l].min(h[r])*len
    }

    pub fn max_area(height: Vec<i32>) -> i32 {
        let len=height.len();
        let mut l=0;
        let mut r=len-1;
        let mut max=0;
        
        let mut tmp;

        while l<r{
            tmp=Solution::get_area(&height,l,r);
            if tmp>max{
                max=tmp;
            }

            if height[l]<height[r]{
                l+=1;
            }else{
                r-=1;
            }
        }
        max
    }
}
*/
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = height.len() - 1;
        let mut max = 0;

        while l < r {
            let area = (r - l) as i32 * height[l].min(height[r]);
            max = max.max(area);

            if height[l] < height[r] {
                l += 1;
            } else {
                r -= 1;
            }
        }
        max
    }
}
