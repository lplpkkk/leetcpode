class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int len=s.length();

        for(int i=0;i<len;i++){
            if(i%2==0){
                if(s[i]=='1'){
                    ans+=1;
                }
            }else{
                if(s[i]=='0'){
                    ans+=1;
                }
            }
        }

        return min(ans,len-ans);
    }
};
