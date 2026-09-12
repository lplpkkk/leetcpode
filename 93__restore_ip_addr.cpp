class Solution {
public:
    vector<string> ans;

    void dfs(string s, int idx, string cur_str, int cur_elem){

        if(cur_elem==4){
            if(idx==s.length()){
                cur_str.pop_back();
                ans.push_back(cur_str);
            }    
        }

        if(idx==s.length()) return;
        
        for(int len=1;len<=3;len++){
            if((idx+len)>s.length()) break;

            string part=s.substr(idx,len);

            if(part.length()>1&&part[0]=='0') break;

            int val=stoi(part);

            if(val>255) break;

            dfs(s,idx+len,cur_str+part+'.',cur_elem+1);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,"",0);
        return ans;              
    }
};
