class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddval=0;
        int evenval=0;

        for(int i=1;i<=2*n;i++){
            if((i&1)==1){
                oddval+=i;
            }else{
                evenval+=i;
            }
        }
        return gcd(oddval,evenval);
    }
};
