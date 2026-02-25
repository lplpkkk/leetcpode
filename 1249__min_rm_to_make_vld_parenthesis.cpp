
//  "lee(t(c)o)de"
//       
// st 


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int len=s.length();

        for(int i=0;i<len;i++){
            if(s[i]=='('){
                st.push(i);
            }else if (s[i]==')'){
                if(st.empty()){
                    //invalid ch
                    s[i]='*';
                }else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            int idx=st.top();
            s[idx]='*';
            st.pop();
        }
        
        string ans;
        for(int i=0;i<len;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};
