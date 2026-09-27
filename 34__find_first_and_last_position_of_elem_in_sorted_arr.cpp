class Solution {

    int find_left(vector<int>& nums, int target, int l,int cur){
        int r=cur;
        int ans=cur;

        while(r<nums.size()&&l<=r){
            int m=l+(r-l)/2;

            if(nums[m]==target){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return ans;
    }

    int find_right(vector<int>& nums, int target, int r,int cur){
        int l=cur;
        int ans=cur;
        
        while(r<nums.size()&&l<=r){
            int m=l+(r-l)/2;

            // 2 2 2 3 4 , cand can only > cur 
            if(nums[m]==target){
                ans=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }

        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int find_idx=INT_MAX;
        vector<int> ans(2,-1);

        //find the first match
        while(l<nums.size()&&l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                find_idx=m;
                ans[0]=find_left(nums,target,l,m);
                ans[1]=find_right(nums,target,r,m);
                break;
            }

            if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }      
        return ans;
    }
    
};
