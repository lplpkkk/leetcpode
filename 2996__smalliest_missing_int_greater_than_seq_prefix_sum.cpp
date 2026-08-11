class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int longest_prefix=INT_MIN;
        int idx=1;
        int sum=nums[0];
        unordered_set<int> set;
        set.insert(nums[0]);
        
        while(idx<nums.size()&&nums[idx]==nums[idx-1]+1){
            sum+=nums[idx];
            set.insert(nums[idx]);
            idx++;
        }

        while(idx<nums.size()){
            set.insert(nums[idx]);
            idx++;
        }

        while(set.count(sum)){
            sum++;
        }

        return sum;
    }
};
