impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut ans=0;

        for num in nums{
            ans+= Self::get_four_sum(num);
        }
        ans
    }
    
    fn get_four_sum(num:i32)->i32{
        let mut sum=0;
        let mut cnt=0;

        let lim=(num as f64).sqrt() as i32;

        for i in 1..=lim{
            if num%i==0{
                cnt+=1;
                sum+=i;
                if i*i!=num{
                    cnt+=1;
                    sum+=num/i;
                }
            }
            
            if cnt>4{
                return 0;
            }
        }
        
        if cnt==4{
            sum
        }else{
            0
        }

    }
}
