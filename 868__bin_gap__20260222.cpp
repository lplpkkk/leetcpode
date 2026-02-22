class Solution {
public:
    int binaryGap(int n) {
        int ans=0;//1
        int last1=-1;//2
        int cur=0;//2

        while(n>0){
            if ((n&1)==1){
                if (last1!=-1){
                    if((cur-last1)>ans){
                        ans=(cur-last1);
                    }
                }
                last1=cur;
            }
            
            n>>=1;
            cur+=1;
        }

        return ans;
    }
};
