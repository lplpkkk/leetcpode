class Solution {
public:
    string rev(string& s,int& idx,bool needrev){
        string tmp="";
    
        while(idx<s.length()&&s[idx]!=')'){
            if(s[idx]=='('){
                idx++;
                tmp+=rev(s,idx,true);
                idx++;
            }else{
                tmp+=s[idx];
                idx++;
            }
        }
        if(needrev){
            reverse(tmp.begin(),tmp.end());
        }
        
        return tmp;
    }
    string reverseParentheses(string s) {
        int idx=0;
        return rev(s,idx,false);
    }
};
