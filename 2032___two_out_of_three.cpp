class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
       int exist[101]={0};
       for(int num: nums1) exist[num]|=1;
       for(int num: nums2) exist[num]|=2;
       for(int num: nums3) exist[num]|=4;

        vector<int> ans;
       for(int i=1;i<=100;i++){
            if((exist[i]&(exist[i]-1))!=0){
                ans.push_back(i);              
            }
       }
       return ans;
    }
};
