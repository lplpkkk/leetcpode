class Solution {
public:
    long long titleToNumber(string col) {
        long long cnt=1;
        int ans=0;

        for(int i=col.length()-1;i>=0;i--){
            int val=col[i]-'A'+1;

            ans+=(val*cnt);
            cnt*=26;    
        }

        return ans;
    }
};
