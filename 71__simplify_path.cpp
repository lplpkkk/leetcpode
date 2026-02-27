class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string res, tmp;
        stringstream ss(path);

        while(getline(ss,tmp,'/')){
            if(tmp==""||tmp=="."){
                continue;
            }else if(tmp==".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(tmp);
            }
        }

        for(string s:st){
            res+="/"+s;
        }
        return res.empty()? "/":res;
    }
};
