class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1_len=nums1.size();
        int n2_len=nums2.size();
        int ans=0;

        if(n2_len&0x1){
            for(int n:nums1){
                ans^=n;
            }
        }

        if(n1_len&0x1){
            for(int n:nums2){
                ans^=n;
            }
        }

        return ans;

    }
};
