class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int len=s.length();
        int ans=0;
        int num=0;
        char last_sign='+';

        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }

            if((!isdigit(s[i])&&s[i]!=' ')||i==(len-1)){
                if(last_sign=='+'){
                    st.push(num);
                }else if(last_sign=='-'){
                    st.push(-num);
                }else if(last_sign=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*num);
                }else if(last_sign=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/num);
                }

                last_sign=s[i];
                num=0;
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};
