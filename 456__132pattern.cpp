class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len=nums.size();
        stack<int> st;// this is used to maintain largest '2' cand
        int second=INT_MIN;

        // --------------------
        //  stack->比你小的最大           
        for(int i=len-1;i>=0;i--){
            //current as '1'
            if(nums[i]<second) return true;

            // current as '3'
            while(!st.empty()&&nums[i]>st.top()){
                second=st.top();
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;
    }
};
