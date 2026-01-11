impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty(){
            return 0;
        }    

        let cols=matrix[0].len();
        let mut h=vec![0;cols];
        let mut max_a=0;

        for r in matrix{
            for (i,ch) in r.iter().enumerate(){
                if *ch=='1'{
                    h[i]+=1;
                }else{
                    h[i]=0;
                }
            }
            max_a=max_a.max(Self::max_rec(&h));
        }
        max_a
    
    }

    fn max_rec(heights:&Vec<i32>)->i32{
        let mut stack=Vec::new();
        let mut max_a=0;

        for (i,&h) in heights.iter().enumerate(){
            while let Some(&top_idx)=stack.last(){
                if heights[top_idx]>h{
                    stack.pop();
                    let h=heights[top_idx];
                    let w=if let Some(&prev_idx)=stack.last(){
                        i as i32-prev_idx as i32-1
                    }else{
                        i as i32
                    };
                    max_a=max_a.max(h*w);
                }else{
                    break;
                }
            }
            stack.push(i);
        }

        while let Some(top_idx)=stack.pop(){
            let h=heights[top_idx];
            let w=if let Some(&prev_idx)=stack.last(){
                heights.len() as i32-prev_idx as i32-1
            }else{
                heights.len() as i32
            };
            max_a=max_a.max(h*w)
        }
        max_a
    }
}
