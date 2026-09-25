class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52,0);
        for(char c:s){
            if(c>='a'){
                freq[c-'a']+=1;
            }else{
                freq[c-'A'+26]+=1;
            }
        }

        int pair_cnt=0;
        bool odd_left=false;

        for(int i=0;i<52;i++){
            pair_cnt+=(freq[i]/2);
            if(freq[i]&1){
                odd_left=true;
            }
        }

        return (2*pair_cnt)+(odd_left?1:0);
    }
};
