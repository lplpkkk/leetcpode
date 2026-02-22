class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> res;
        vector<int> cur;

        vector<bool> used(len,false);
        bt(nums,used, cur, res);

        return res;
    }

private:
    void bt(vector<int>& nums,vector<bool>& used, vector<int>& cur, vector<vector<int>>& res){
        if(cur.size()==nums.size()){
            res.push_back(cur);
        }

        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                //push_back this
                cur.push_back(nums[i]);
                used[i]=1;

                //back trace
                bt(nums,used,cur,res);

                //pop_back
                cur.pop_back();
                used[i]=0;
            }
        }
    }

};
