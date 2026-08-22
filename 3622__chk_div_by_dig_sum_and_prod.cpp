class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1;
        int n2=n;
        
        while(n2){
            sum+=(n2%10);
            prod*=(n2%10);
            n2/=10;
        }

        return ((n%(sum+prod))==0);

    }
};
