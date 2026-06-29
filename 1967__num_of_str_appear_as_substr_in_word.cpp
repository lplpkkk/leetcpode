
/*
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;

        for(auto& s:patterns){
            int n=s.length();
            int srch_idx=0;
            int word_len=word.length();

            while(word[srch_idx]!=s[0] && srch_idx<word_len){
                srch_idx++;
            }
            
            if((word_len-srch_idx)<n){
                continue;
            }

            int pass=1;

            for(int i=0;i<n;i++){
                if(word[srch_idx+i]!=s[i]){
                    pass=0;
                    break;
                }
            }

            if(pass){
                ans+=1;
            }
        }

        return ans;
    }
};
*/

class Solution{
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto& s:patterns){
            if(word.find(s)!=string::npos){
                ans++;
            }
        }

        return ans;

    }
};
