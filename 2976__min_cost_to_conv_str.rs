impl Solution {
    pub fn minimum_cost(source: String, target: String, original: Vec<char>, changed: Vec<char>, cost: Vec<i32>) -> i64 {
        let INF=i64::MAX/2;
        let len=original.len();

        //setup all map
        let mut dist=vec![vec![INF;26];26];

        for i in 0..26{
            dist[i][i]=0;
        }

        for i in 0..len{
            let u=(original[i] as u8 -b'a')as usize;
            let v=(changed[i] as u8 -b'a')as usize;
            let w=(cost[i])as i64;
            dist[u][v]=dist[u][v].min(w);
        }

        for k in 0..26{
            for i in 0..26{
                for j in 0..26{
                    dist[i][j]=dist[i][j].min(dist[i][k]+dist[k][j]);
                }
            }
        }
        
        let mut ans=0;
        let s_bytes=source.as_bytes();
        let t_bytes=target.as_bytes();
        for i in 0..source.len(){
            let s=(s_bytes[i]- b'a') as usize;
            let t=(t_bytes[i] - b'a') as usize;
            if dist[s][t]==INF{
                return -1;
            }
            ans+=dist[s][t];
        }
        ans
        
    }
}
