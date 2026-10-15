class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int len=nums.size();

        for(int i=0;i<len;i++){
            set<int> seen;
            
            for(int j=i;j<len;j++){
                if(seen.count(nums[j])==0){
                    seen.insert(nums[j]);
                }
                ans+=seen.size()*seen.size();
            }
            
        }
        return ans;
    }
};
