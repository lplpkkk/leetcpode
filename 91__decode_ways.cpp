class Solution {
public:

/*
    int dfs(string s, int idx, int cnt){
        int lim=s.length();
        
        if(idx>=lim){
            return cnt;
        }

        if(s[idx]>3){
            //only one possibility
            return dfs(s,idx+1,cnt);
        }else{
            if(s[idx]==0){
                return 0;
            }else if(idx==(lim-1)){
                //only one possibility
                return dfs(s,idx+1,cnt);
            }else{
                //select one or two char
                return dfs(s,idx+1,cnt)+dfs(s,idx+2,cnt);
            }
        }
    }
  */

    vector<int> memo;

    int dfs(string& s, int idx){
        int len=s.length();

        if(idx==len) return 1;
        
        if(s[idx]=='0') return 0;

        if(memo[idx]!=-1) return memo[idx];

        int ans=dfs(s,idx+1);

        if(idx+1<len){
            int val=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(val>=10&&val<=26){
                ans+=dfs(s,idx+2);
            }
        }


        return memo[idx]=ans;
    }

    int numDecodings(string s) {
        memo.assign(s.length(),-1);
        return dfs(s,0);
    }
};
