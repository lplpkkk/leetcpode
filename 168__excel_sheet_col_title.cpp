class Solution {
public:
    string convertToTitle(int col) {
        string ans="";

        while(col>0){
            col--;//from 1-based to 0-based
            int remain=col%26;
            ans.push_back('A'+remain);

            col/=26;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
