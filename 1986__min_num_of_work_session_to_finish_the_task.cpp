/*
class Solution {
public:
    int ans=INT_MAX;

    void dfs(vector<int>& left, int cur_sum, int cap, int cnt){
       if(left.size()==0){
        ans=min(ans,cnt+(cur_sum>0));
        return;
       }

       for(int i=0;i<left.size();i++){
            //select left[i]
            int tmp_elem=left[i];
            int tmp_sum=cur_sum+left[i];
            left.erase(left.begin()+i);
            if((cur_sum+tmp_elem)<=cap){
                dfs(left,tmp_sum,cap,cnt);
            }else{
                dfs(left,tmp_elem,cap,cnt+1);
            }
            
            left.insert(left.begin()+i,tmp_elem);
       } 

       
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> cur=tasks;

        dfs(cur,0,sessionTime,0);
        
        return ans;
    }
};
*/

class Solution {
public:
    //memo[mask][cur_sum]
    vector<vector<int>> memo;

    int n,cap;
    vector<int> t;

    int dfs(int mask, int cur_sum){
        if(mask==((1UL<<n)-1)){
            return (cur_sum>0)?1:0;
        }

        if(memo[mask][cur_sum]!=-1) return memo[mask][cur_sum];

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(mask&(1UL<<i)) continue;

            int new_mask=mask|(1UL<<i);

            if(cur_sum+t[i]<=cap){
                ans=min(ans,dfs(new_mask,cur_sum+t[i]));
            }else{
                ans=min(ans,1+dfs(new_mask,t[i]));
            }
        }

        memo[mask][cur_sum]=ans;
        return ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        n=tasks.size();
        t=tasks;
        cap=sessionTime;

        memo.assign(1<<n, vector<int>(cap+1,-1));

        return dfs(0,0);
    }
};
