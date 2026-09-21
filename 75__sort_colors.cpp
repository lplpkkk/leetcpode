class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>freq(3);
        for(int n:nums){
            freq[n%3]++;
        }

        int idx=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<freq[i];j++){
                nums[idx++]=i;
            }
        }

        return;
    }
};
