class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len=nums.size();
        vector<int> ans(len);
        vector<int> last(32,-1);//the most right bit that has 1

        for(int i=len-1;i>=0;i--){
            int end=i;

            for(int bit=0;bit<32;bit++){
                if(nums[i]&(1<<bit)){
                    last[bit]=i;
                }

                if(last[bit]!=-1){
                    end=max(end,last[bit]);
                }
            }

            ans[i]=end-i+1;
            
        }

        return ans;
    }
};
