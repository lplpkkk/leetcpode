
/*
class Solution {
public:
    int ans=0;

    void dfs(string s, string t,int s_idx, int t_idx, int s_sz, int t_sz){
        
        while(s_idx<s_sz && t_idx<t_sz){
            if(s[s_idx]==t[t_idx]){
                s_idx++;
                t_idx++;
            }else{
                dfs(s,t,s_idx+1, t_idx, s_sz,t_sz);
                break;
            }
        }

        if(t_idx==t_sz){
            ans++;
            return ;
        }

        return;
    }

    int numDistinct(string s, string t) {
        int s_len=s.length();
        int t_len=t.length();

        if(s_len<t_len) return 0;

        for(int i=0;i<s_len;i++){
            dfs(s,t,i,0,s_len,t_len);
        }

        return ans;
    }
};
*/


class Solution {
public:
    vector<vector<long long>> memo;

    long long dfs(string& s, string& t, int i, int j){

        if(j==t.size()){
            return 1;
        }

        if(i==s.size()){
            return 0;
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        
        long long ans=dfs(s,t,i+1,j);

        if(s[i]==t[j]){
            ans+=dfs(s,t,i+1,j+1);
        }

        return memo[i][j]=ans;
    }

    int numDistinct(string s, string t) {
        memo.assign(s.size(), vector<long long> (t.size(),-1));
        return dfs(s,t,0,0);
    }
};
