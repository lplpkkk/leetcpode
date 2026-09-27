class Solution {
public:
    vector<int> ori;
    int len;

    Solution(vector<int>& nums) {
        ori=nums;
        len=nums.size();
    }
    
    vector<int> reset() {
        return ori;
    }
    
    vector<int> shuffle() {
        vector<int> ans=ori;
        for(int i=0;i<len;i++){
            int newpos=i+(rand()%(len-i));
            swap(ans[i],ans[newpos]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
