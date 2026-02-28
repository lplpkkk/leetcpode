class Solution {
public:
    int concatenatedBinary(int n) {
        int bitlen=0;
        int MOD=1e9+7;
        long long ans=0;

        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                //power of 2
                bitlen+=1;
            }
            ans=((ans<<bitlen)+i)%MOD;
        }

        return (int)ans;

    }
};
