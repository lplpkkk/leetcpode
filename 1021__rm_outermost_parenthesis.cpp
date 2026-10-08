class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int bal=0;
        int start_idx=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                bal++;
            }else{
                bal--;
            }

            if(bal==0){
                ans+=s.substr(start_idx+1,i-start_idx-1);
                start_idx=i+1;
            }
        }

        return ans;
    }
};
