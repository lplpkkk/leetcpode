class Solution {
public:
    int ans=0;

    void dfs(vector<string>& s, int idx, string tmp, int set){
        if(idx==s.size()){
            ans=max(ans,(int)tmp.size());
            return;
        }

        dfs(s,idx+1,tmp,set);

        string new_elem=s[idx];
        
        for(char c: new_elem){
            int bit=c-'a';
            if(((set&(1<<bit))!=0)){
                return;
            }else{
                set|=(1<<bit);
            }
        }

        dfs(s,idx+1,tmp+s[idx],set);
    }

    int maxLength(vector<string>& arr) {
        dfs(arr, 0, "",0);
        return ans;
    }
};
