class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;

            //handle the duplicate
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }

            //optimize
            if(nums[i]>0){
                continue;
            }

            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum+nums[i]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l+=1;
                    r-=1;
                    
                    //handle duplicate
                    while(l<r && nums[l]==nums[l-1]){
                        l+=1;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r-=1;
                    }
                }else if(sum+nums[i]>0){
                    r-=1;
                }else{//too small
                    l+=1;
                }
            }
        }

        return ans;
    }
};
