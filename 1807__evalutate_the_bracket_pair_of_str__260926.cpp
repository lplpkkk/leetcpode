class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        //store in hash map
        unordered_map<string, string> map;
        for(auto& k:knowledge){
            map[k[0]]=k[1];
        }

        string ans;

        for(int i=0;i<s.length();i++){
            int end=i;
            if(s[i]=='('){
                while(s[end]!=')'){
                    end++;
                }
                
                string key=s.substr(i+1,end-i-1);
                if(map.count(key)){
                    ans+=map[key];
                }else{
                    ans+="?";    
                }
                i=end;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
