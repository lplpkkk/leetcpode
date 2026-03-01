class Solution {
public:
    int calculate(string s) {
        // ( --> context store
        //      calc 
        //   )
        stack<int> st;
        int res=0;
        int sign=1; 
        int len=s.length();
        long long this_num=0;

        for(int i=0;i<len;i++){
            int this_c=s[i];

            if(isdigit(this_c)){
                //check multi-digit
                i++;
                this_num=this_c-'0';

                while(i<len && isdigit(s[i])){
                    this_num=this_num*10+(s[i]-'0');
                    i++;
                }
                i--;

                res+=(int)(this_num*sign);

            }else if(this_c=='+'){
                sign=1;
            }else if(this_c=='-'){
                sign=-1;
            }else if(this_c=='('){
                //store context
                st.push(sign);
                st.push(res);
                
                sign=1;
                res=0;

            }else if(this_c==')'){
                if(st.size()==0){
                    //error handling
                }
                //restore context
                int prev_res=st.top();
                st.pop();
                int prev_sign=st.top();
                st.pop();

                res=prev_res+prev_sign*res;
            }
        }

        return res;
        
    }
};
