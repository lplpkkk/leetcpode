class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen;
        for(int n:nums1) if(seen.count(n)==0){ seen.insert(n);}
        vector<int> ans;
        sort(nums2.begin(),nums2.end());
        
        int idx=0;
        int prev=INT_MAX;

        while(idx<nums2.size()&&nums2[idx]!=prev){
            if(seen.count(nums2[idx])!=0){
                ans.push_back(nums2[idx]);
                prev=nums2[idx];

                while(idx<nums2.size()&&nums2[idx]==prev){
                    idx++;
                }
            }else{
                idx++;
            }
        }
        
        return ans;
    }
};
