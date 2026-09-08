/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       pair<int,int> p(0,0);//max_bit, len
       
       for(int l=0;l<nums.size();l++){
            int r=l;
            int mask=nums[l];

            while(l<=r&&r<nums.size()){
                mask&=nums[r];
                if(mask>p.first){
                    p.first=mask;
                    p.second=r-l+1;    
                }else if(mask==p.first){
                    p.second=max(p.second,r-l+1);
                }
                r++;
            }
       }

        return p.second;
       
    }
};
*/


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_v=*max_element(nums.begin(),nums.end());

        int ans=0;
        int cur=0;

        for(int n:nums){
            if(n==max_v){
                cur+=1;
                ans=max(ans,cur);
            }else{
                cur=0;
            }
        }

        return ans;
    }
};
