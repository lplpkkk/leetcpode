class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> eq;
        vector<int> greater;

        for(auto& n:nums){
            if(n<pivot){
                less.push_back(n);
            }else if(n==pivot){
                eq.push_back(n);
            }else{
                greater.push_back(n);
            }
        }

        vector<int> ans;
        ans.reserve(nums.size());

        ans.insert(ans.end(),less.begin(),less.end());
        ans.insert(ans.end(),eq.begin(),eq.end());
        ans.insert(ans.end(),greater.begin(),greater.end());


        return ans;
    }
};
