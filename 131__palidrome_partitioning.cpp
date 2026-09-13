class Solution {
public:

    vector<vector<string>> ans;

    bool is_pal(string s,int l, int r){

        int len=s.length();

        if(len==0) return false;

        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;r--;
        }

        return true;
    }

    void dfs(const string& s, int start, vector<string>& cur){
        if(start==s.size()){
            ans.push_back(cur);
            return;
        }

        for(int end=start;end<s.size();end++){
            if(!is_pal(s,start,end)) continue;

            string tmp=s.substr(start, (end-start+1));
            cur.push_back(tmp);
            dfs(s,end+1,cur);
            cur.pop_back();
        }    
    }

    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(s,0,cur);
        return ans;
    }
};
