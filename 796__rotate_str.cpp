class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.length();
        int len_goal=goal.length();
        int i=0;

        if(len!=len_goal){
            return false;
        }

        vector<int> cand;
        for(i=0;i<len;i++){
            //find the first char
            if(s[i]==goal[0]){
                cand.push_back(i);
            }
        }

        if(cand.size()==0){
            return false;
        }

        for(i=0;i<cand.size();i++){
            bool match=true;
            for(int j=0;j<len;j++){
                if(s[(cand[i]+j)%len]!=goal[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                return true;
            }
        }
        

        return false;
    }
};
