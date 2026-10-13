class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){ return abs(a)>abs(b);});
        long long ans=0;
        int half_idx = (nums.size() + 1) / 2;

        for(int i=0;i<half_idx;i++){
            ans += 1LL * nums[i] * nums[i];
        }
        for(int i=half_idx;i<nums.size();i++){
            ans -= 1LL * nums[i] * nums[i];
        }

        return ans;
    }
};
