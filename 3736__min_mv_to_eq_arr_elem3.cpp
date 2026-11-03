class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_elem=*max_element(nums.begin(),nums.end());
        int ans=0;

        for(int n:nums){
            ans+=(max_elem-n);
        }

        return ans;

    }
};
