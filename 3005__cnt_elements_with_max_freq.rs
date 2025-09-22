use std::collections::HashMap;

impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut freq=HashMap::new();
        let mut max_freq=0;

        for &num in nums.iter(){
            let cnt=freq.entry(num).or_insert(0);
            *cnt+=1;
            if *cnt>max_freq{
                max_freq=*cnt;
            }
        }

        let mut result=0;
        for (_,&f) in freq.iter(){
            if f==max_freq{
                result+=f;
            }
        }
        result 
        
    }
}
