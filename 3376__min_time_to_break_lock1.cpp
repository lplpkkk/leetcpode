class Solution {
public:
    int len;
    int _fullmask;
    vector<int> memo;
    
    int dfs(vector<int>& strength, int k,int mask,int x){
        if(mask==_fullmask){
            return 0;
        }

        if(memo[mask]!=-1) return memo[mask];

        int ans=INT_MAX;

        for(int i=0;i<len;i++){

            if(mask&(1<<i)) continue;
            
            int need_time=(strength[i]+x-1)/x;
            int newmask=mask|1<<i;
            int newx=x+k;

            ans=min(ans,need_time+dfs(strength,k,newmask,newx));
        }

        return memo[mask]=ans;
    }

    int findMinimumTime(vector<int>& strength, int k) {
        int n=strength.size();
        len=n;
        _fullmask= (1<<n)-1;

        memo.assign(1<<n, -1);

        return dfs(strength,k,0,1);
    }
};
