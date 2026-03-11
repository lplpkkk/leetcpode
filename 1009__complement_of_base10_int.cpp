class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        int shift=0;

        if(n==0) return 1;

        while(n){
            int flip=(n&1)^1;

            ans|=((flip)<<shift);
            n>>=1;  
            shift++;
        }

        return ans;
    }
};
