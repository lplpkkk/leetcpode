class Solution {
public:
    int calc(int n){
        string s=to_string(n);
        int sum=0;

        for(char c:s) sum+=c-'0';

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        
        for(int i=0;i<nums.size();i++){
            if(calc(nums[i])==i) return i;
        }

        return ans;
    }
};
