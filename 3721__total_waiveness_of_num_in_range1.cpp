class Solution {
public:

    int totalWaviness(int num1, int num2) {
        int num=num1;
        int ans=0;
        
        while(num<=num2){
            string s=to_string(num);
            int len=s.length();

            if(len<3){
                num++;
                continue;
            }        

            for(int i=1;i<len-1;i++){
                if(s[i]>s[i+1] && s[i-1]<s[i]){
                    ans+=1;
                }
                if(s[i]<s[i+1] && s[i-1]>s[i]){
                    ans+=1;
                }
            }
            num++;
        }

        return ans;
    }
};
