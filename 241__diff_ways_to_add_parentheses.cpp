class Solution {
public:
    vector<int> dfs(string s){
        int len=s.length();
        vector<int> ans;

        for(int i=0;i<len;i++){
            char op=s[i];

            if(op!='+'&&op!='-'&&op!='*') continue;

            vector<int> l=dfs(s.substr(0,i));
            vector<int> r=dfs(s.substr(i+1));

            for(int nl:l){
                for(int nr:r){
                    if(op=='+'){
                        ans.push_back(nl+nr);
                    }else if(op=='-'){
                        ans.push_back(nl-nr);
                    }else if(op=='*'){
                        ans.push_back(nl*nr);
                    }
                }
            }    
        }

        if(ans.empty()){
            ans.push_back(stoi(s));
        }      

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);      
    }
};
