class Solution {
public:
    int prod(int n){
        int ans=1;
        while(n){
            ans*=n%10;
            n/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int p=prod(n);
        while(p%t!=0){
            n++;
            p=prod(n);
        }

        return n;
    }
};
