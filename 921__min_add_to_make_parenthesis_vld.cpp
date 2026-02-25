class Solution {
public:
    int minAddToMakeValid(string s) {
        int right_unmatch=0;//
        stack<int> st;//

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
                
            }else{
                if(st.empty()){
                    right_unmatch+=1;
                }else{
                    st.pop();
                }
            }
        }
        return st.size()+right_unmatch;
    }
};
