class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int len =nums.size();
        int ans=0;

        for(int i=0;i<len;i++){
            if(len%(i+1)==0) ans+=(nums[i]*nums[i]);
        }

        return ans;
    }
};
