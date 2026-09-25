class Solution {

    // a{b,c}d

public:
    vector<string> uni(vector<string> a, vector<string> b){
        set<string> seen;
        vector<string> ans=a;
        
        for(auto& e:a) seen.insert(e);
        for(auto& e:b){
            if(seen.count(e)==0){
                ans.push_back(e);
                seen.insert(e);
            }
        }

        return ans;
    }

    vector<string> concat(vector<string> a, vector<string> b){
        vector<string> ans;
        for(auto& e_a:a){
            for(auto& e_b:b){
                string tmp=e_a+e_b;
                ans.push_back(tmp);
            }
        }

        return ans;
    }


    vector<string> dfs(string& s, int& idx){
        int len=s.length();
        vector<string> tmp={""};// this is for concat
        vector<string> res;//this is for union

        while(idx<len && s[idx]!='}'){
            if(s[idx]==','){
                res=uni(res,tmp);
                tmp={""};
                idx++;
            }else if(s[idx]=='{'){
                idx++;
                vector<string> inside=dfs(s,idx);
                idx++;
                tmp=concat(tmp,inside);
            }else{
                vector<string> letter={string(1,s[idx])};
                tmp=concat(tmp,letter);
                idx++;
            }
        }
        
        res=uni(res,tmp);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int idx=0;
        vector<string> ans=dfs(expression,idx);      
        sort(ans.begin(),ans.end());

        return ans;
    }
};
