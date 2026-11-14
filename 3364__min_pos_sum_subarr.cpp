class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            for(int j=l;j<=r && i+j<=n;j++){
                int tmp_sum=0;
                for(int k=0;k<j;k++){
                    tmp_sum+=nums[i+k];
                }
                if(tmp_sum>0){
                    ans=min(ans,tmp_sum);
                }
                
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
