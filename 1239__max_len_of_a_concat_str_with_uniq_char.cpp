class Solution {
public:
    int ans=0;

    void dfs(vector<string>& s, int idx, string tmp, unordered_set<int> set){
        if(idx==s.size()){
            ans=max(ans,(int)tmp.size());
            return;
        }

        dfs(s,idx+1,tmp,set);

        string new_elem=s[idx];
        for(char c: new_elem){
            if(set.count(c)!=0){
                return;
            }else{
                set.insert(c);
            }
        }

        dfs(s,idx+1,tmp+s[idx],set);
    }

    int maxLength(vector<string>& arr) {
        unordered_set<int> set;
        dfs(arr, 0, "",set);
        return ans;
    }
};
