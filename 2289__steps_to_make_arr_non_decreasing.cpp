class Solution {
public:
    int totalSteps(vector<int>& nums) {
        // val, round_to_be_killed
        vector<pair<int,int>> st;
        int ans=0;

        for(int x:nums){
            int step=0;

            while(!st.empty()&& st.back().first<=x){
                step=max(step,st.back().second);
                st.pop_back();
            }

            if(!st.empty()){
                step++;
            }else{
                step=0;
            }

            ans=max(ans,step);
            st.push_back({x,step});
        }

        return ans;
    }
};
