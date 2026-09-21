class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> seen;

    void dfs(vector<int>& num, int cnt, int mask, vector<int>& cur){
        // x x x 
        // v v 
        int len=num.size();
        if(cnt==len){
            if(seen.count(cur)==0){
                ans.push_back(cur);
                seen.insert(cur);
            }
        }
        
        for(int i=0;i<len;i++){
            if((mask&(1<<i))==0){
                cur.push_back(num[i]);
                dfs(num,cnt+1,mask|(1<<i),cur);
                cur.pop_back();
            }
        }
        
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<int> tmp;

        dfs(nums,0,0,tmp);
        

        return ans;
    }
};
