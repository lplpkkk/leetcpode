class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int len=nums.size();
        vector<int> ls(len,0);
        vector<int> rs(len,0);
        int i=0;

        for(int i=1;i<len;i++){
            ls[i]=ls[i-1]+nums[i-1];
        }

        for(int i=len-2;i>=0;i--){
            rs[i]=rs[i+1]+nums[i+1];
        }

        vector<int> ans(len,0);

        for(int i=0;i<len;i++){
            ans[i]=abs(ls[i]-rs[i]);
        }

        return ans;
    }
};
