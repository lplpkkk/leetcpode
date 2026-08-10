class Solution {
    
public:
    vector<int> cand;
    vector<int> memo;

    bool dfs(int n){
        if(n==0){
            return false;
        }

        if(memo[n]!=-1){
            return memo[n];
        }

        for(int x:cand){
            if(x>n){
                break;
            }

            if(!dfs(n-x)){
                return memo[n]=true;
            }
        }

        return memo[n]=false;
    }

    bool winnerSquareGame(int n) {
        for(int i=1;i*i<=n;i++){
            cand.push_back(i*i);
        }

        memo.assign(n+1,-1);

        return dfs(n);
    }
};
