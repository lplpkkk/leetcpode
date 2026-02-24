/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* ans=malloc(sizeof(int)*2);
    ans[0]=-1;
    ans[1]=-1;

    //------------
    // |      |
    //|    |  x m   |
    //l          r
    int l=0;
    int r=numsSize-1;
    
    //finding the upper boundary
    while(l<=r){
        int m=l+(r-l)/2;
        if(nums[m]<=target){
            if (nums[m]==target){
                ans[1]=m;
            }
            l=m+1;
        }else{
            r=m-1;
        }
    }

    l=0;
    r=numsSize-1;

    //find the lower boundary:
    while(l<=r){
        int m=l+(r-l)/2;
        if(nums[m]>=target){
            if(nums[m]==target){
                ans[0]=m;
            }
            r=m-1;
        }else{
            l=m+1;
        }
    }

    return ans;
    
}
