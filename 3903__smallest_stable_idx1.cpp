class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> max_cand(nums.size());
        vector<int> min_cand(nums.size());

        if(nums.size()==1){
            return (0<=k)?0:-1;
        }else{
            max_cand[0]=nums[0];
            min_cand[nums.size()-1]=nums[nums.size()-1];
        }

        for(int i=1;i<nums.size();i++){
            max_cand[i]=max(max_cand[i-1],nums[i]);    
        }

        for(int i=nums.size()-2;i>=0;i--){
            min_cand[i]=min(min_cand[i+1],nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if((max_cand[i]-min_cand[i])<=k){
                return i;
            }
        }

        return -1;
        
    }
};
