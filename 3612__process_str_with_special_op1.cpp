class Solution {
public:
    string processStr(string s) {
        string ans="";
        char last_c='@';

        for(auto& c:s){
            if(c=='*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }else if (c=='#'){
                if(last_c!='@'){
                    ans+=ans;
                }
            }else if (c=='%'){
                int n=ans.length();
                for(int i=0;i<n/2;i++){
                    swap(ans[i],ans[n-1-i]);
                }
            }else{
                ans.push_back(c);
                last_c=c;
            } 
        }

        return ans;
    }
};
