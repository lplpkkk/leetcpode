class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // add the knowledge to the hash map
        unordered_map<string, string> hm;
        
        for(int i=0;i<knowledge.size();i++){
            hm[knowledge[i][0]]=knowledge[i][1];
        }

        stringstream ss;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                string key="";
                i++;
                while(i<s.length()&&s[i]!=')'){
                    key+=s[i];
                    i+=1;
                }

                if (hm.count(key)){
                    ss<<hm[key];
                }else{
                    ss<<"?";
                }
            }else{
                ss<<s[i];
            }
        }

        return ss.str();
        
    }
};
