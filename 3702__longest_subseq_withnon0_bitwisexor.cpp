class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int has_no_zero=false;

        for(int n:nums){
            x^=n;
            if(n!=0){
                has_no_zero=true;
            }
        }

        if(x!=0){
            return nums.size();
        }

        if(has_no_zero){
            return nums.size()-1;
        }

        return 0;
    }
};
