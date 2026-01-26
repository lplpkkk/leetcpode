impl Solution {
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        arr.sort_unstable();
        let mut min_diff=i32::MAX;
        let mut ans=Vec::new();

        for i in 1..arr.len(){
            let this_diff=arr[i]-arr[i-1];
            if this_diff<min_diff{
                min_diff=this_diff;
                ans.clear();
                ans.push(vec!(arr[i-1],arr[i]));
            }else if this_diff==min_diff{
                ans.push(vec!(arr[i-1],arr[i]));
            }
        }
        ans
    }
}
