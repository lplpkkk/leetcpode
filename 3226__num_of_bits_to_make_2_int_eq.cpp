class Solution {
public:
    int minChanges(int n, int k) {
        int diff=n^k;
        int ans=0;

        for(int i=0;i<21;i++){
            if(( diff & (1UL<<i) )!=0){
                if(( n&(1ULL<<i))==0){
                    return -1;
                }else{
                    ans++;
                }
            }
        }

        return ans;
    }
};
