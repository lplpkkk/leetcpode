class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());

        int last_data=nums[nums.size()-1];
        int try_idx=1;

        while(try_idx*k<=last_data){
            if(set.count(try_idx*k)==0){
                return try_idx*k;
            }    
            try_idx++;
        }

        return try_idx*k;
    }
};
