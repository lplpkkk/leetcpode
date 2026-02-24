class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();

        //this is an index stack
        stack<int> st;
        st.push(-1);
        int max_len=0;

        //st: 0 1

        for(int i=0;i<len;i++){
            if (s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    //cannot be longer anymore, restart the starting point
                    st.push(i);
                }
                else{
                    //update cuurent long 
                    max_len=max(max_len, i-st.top());
                }
            }
        }

        return max_len;
    }
};
