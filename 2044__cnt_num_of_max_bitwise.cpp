class Solution {
public:
    int ans=0;
    int target;

    void dfs(vector<int>& nums, int idx, int cur){
        if(idx==nums.size()){
            if(cur==target){
                ans++;
            }
            return;
        }

        dfs(nums,idx+1, cur);
        dfs(nums,idx+1, cur|nums[idx]);

    }

    int countMaxOrSubsets(vector<int>& nums) {
        for(int n:nums){
            target|=n;
        }

        dfs(nums,0,0);

        return ans;
    }
};
