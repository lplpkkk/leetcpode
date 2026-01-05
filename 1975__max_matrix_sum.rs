impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut total_sum:i64=0;
        let mut min_abs=i32::MAX;
        let mut neg_cnt=0;

        for &val in matrix.iter().flatten(){
            let abs_val=val.abs();
            
            if abs_val<min_abs{
                min_abs=abs_val;
            }

            if val<0{
                neg_cnt+=1;
            }

            total_sum+=abs_val as i64;
        }

        if neg_cnt%2==0{
            total_sum
        }else{
            total_sum-2*(min_abs as i64)
        }
    }
}
