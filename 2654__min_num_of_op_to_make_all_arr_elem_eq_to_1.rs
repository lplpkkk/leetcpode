impl Solution {
    pub fn gcd(mut a:i32, mut b:i32)->i32{
        while a>0 && b>0{
            if a>b{
                a=a-b;
            }else{
                b=b-a;
            }
        }
        if b==0{
            a
        }else{
            b
        }
    }

    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut n=nums.len();

        /*  get num of ones */
        let mut n1 = nums.iter().filter(|&&x| x==1).count();
        if n1!=0{
            return (n-n1) as i32;
        }

        /* check if it is possible */
        let mut g=nums[0];
        for &x in &nums{
            g=Self::gcd(x,g);
        }

        /* impossible case */
        if g!=1{
            return -1;
        }

        let mut min_len=n as i32;
        for i in 0..n{
            let mut g = nums[i];
            for j in i+1..n{
                g=Self::gcd(nums[j],g);
                if g==1{
                    min_len=min_len.min((j-i+1) as i32);
                    break;
                }
            }
        }

        (min_len-1)+n as i32 -1
               
    }
}
