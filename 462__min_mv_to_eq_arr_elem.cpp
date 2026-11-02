class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int med=nums[nums.size()/2];

        int ans=0;

        for(int n:nums){
            ans+=abs(n-med);
        }

        return ans;
    }
};
