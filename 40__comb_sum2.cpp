class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> seen;
    
    //->[1,1,2,5,6,7,10]
    //     |
    //   |
    //   {1},1,1
    //      |
    //       {1,1},2,2
    //            |
    //             {1,1,6}

    void dfs(vector<int>& cand,vector<int>& cur,int idx,int cur_sum,int target){
        if(idx>(cand.size()-1)||cur_sum>target||cand[idx]>target) return;

        //skip this one
        int next=idx+1;
        while(next<cand.size()&&cand[next]==cand[idx]){
            next++;
        }
        dfs(cand,cur,next,cur_sum,target);

        //try this one
        cur.push_back(cand[idx]);

        if((cur_sum+cand[idx])==target){
            if(seen.count(cur)==0){
                ans.push_back(cur);
                seen.insert(cur);
            }
        }else{
            dfs(cand,cur,idx+1,cur_sum+cand[idx],target);
        }

        cur.pop_back();
    }

    //[10,1,2,7,6,1,5]
    //->[1,1,2,5,6,7,10]
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());//optional?
        vector<int> tmp;
        dfs(cand,tmp,0,0,target);

        return ans;
    }
};
