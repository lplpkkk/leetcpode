class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int> seen(26,0);

        for(int i=0;i<n;i++){
            int idx=0;
            if(word[i]>='a'){
                idx=word[i]-'a';
                seen[idx]|=1;
            }else{
                idx=word[i]-'A';
                seen[idx]|=2;
            }
        }    

        int res=0;
        for(int i=0;i<26;i++){
            if(seen[i]==3){
                res++;
            }
        }

        return res;
    }
};
