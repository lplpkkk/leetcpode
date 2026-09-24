#define LIM ((1<<9)-1)

class Solution {
public:
    vector<vector<int>> ans;
    

    void dfs(int k, int n, int start,int mask, vector<int> cur){

        if(k==0){
            if(n==0){
                ans.push_back(cur);
            }
            return;
        }
        
        for(int i=start;i<=9;i++){
            if((mask&(1<<i))==0){
                if(i<=n){
                    cur.push_back(i);
                    dfs(k-1,n-i,i+1,mask|1<<i,cur);
                    cur.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(k,n,0,1,tmp);

        return ans;
    }
};
