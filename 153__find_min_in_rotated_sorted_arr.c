#define MIN(a,b) ((a<b)?a:b)

int findMin(int* nums, int numsSize) {
    int l=0, r=numsSize-1;
    int ans=INT_MAX;
    
    while(l<=r&&l<numsSize){
        int m=l+(r-l)/2;
        if(nums[m]>nums[r]){
            l=m+1;
        }else{
            r=m-1;
        }
        ans=MIN(ans,nums[m]);
    }

    return ans;
}
