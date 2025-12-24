impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, capacity: Vec<i32>) -> i32 {
        let mut sum_apple:i32=apple.iter().sum();
        let mut capacity=capacity;
        capacity.sort_unstable_by(|a,b| b.cmp(a));
        let mut ans=0;

        for cap in capacity{
            sum_apple-=cap;
            ans+=1;
            if sum_apple<=0{
                break;
            }
        }
        ans
    }
}
