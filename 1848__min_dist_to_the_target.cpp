class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int len=nums.size();
        int idx=0;

        while( (start-idx)>=0 || (start+idx)<len ){
            if(start>=idx){
                if(nums[start-idx]==target){
                    return idx;
                }
            }
            if((start+idx)<len){
                if(nums[start+idx]==target){
                    return idx;
                }
            }
            idx++;
        }
        
        return -1;
    }
};
