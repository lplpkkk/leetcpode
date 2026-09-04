class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        int offset=0;
        int odd=0;
        int even=0;

        while(n){
            if((n&0x1)==1){
                if((offset&0x1)==0){//even
                    even++;
                }else{
                    odd++;
                }
            }

            offset++;
            n>>=1;
        }    

        ans[0]=even;ans[1]=odd;
        return ans;
    }
};
