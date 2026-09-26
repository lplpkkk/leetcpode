class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
        int ans=0;

        for(int l=0;l<arr.size();l++){
            for(int r=l;r<arr.size();r++){
                if(l==r){
                    dp[l][r]=arr[l];
                }else{
                    dp[l][r]=dp[l][r-1]^arr[r];
                }

                if(dp[l][r]==0){
                    ans+=(r-l);
                }
            }
        }

        return ans;

    }
};
