use std::cmp;

impl Solution {
    pub fn maximize_square_hole_area(n: i32, m: i32, mut h_bars: Vec<i32>, mut v_bars: Vec<i32>) -> i32 {
        h_bars.sort_unstable();
        v_bars.sort_unstable();

        let side=cmp::min(Self::get_cont_len(&h_bars)+1,Self::get_cont_len(&v_bars)+1);
        side*side
    }

    fn get_cont_len(arr: &Vec<i32>)->i32{
        //assume 'arr' is sorted
        let mut max_len=0;

        for i in 0..arr.len(){
            let mut this_val=arr[i];
            let mut len=1;
            for j in i+1..arr.len(){
                if arr[j]==(this_val+1){
                    len+=1;
                    this_val=arr[j];
                }else{
                    break;
                }
            }
            max_len=max_len.max(len);     
        }
        max_len
    }

    /*
    // 優化後的線性搜尋 O(N)
    --> from AI
    fn get_max_consecutive(arr: &[i32]) -> i32 {
        if arr.is_empty() { return 0; }
        
        let mut max_len = 1;
        let mut current_len = 1;
        
        for i in 1..arr.len() {
            if arr[i] == arr[i - 1] + 1 {
                current_len += 1;
            } else {
                max_len = cmp::max(max_len, current_len);
                current_len = 1;
            }
        }
        cmp::max(max_len, current_len)
    }
    */
}
