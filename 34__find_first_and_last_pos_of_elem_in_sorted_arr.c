/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int find_left(int* nums, int numsSize, int target, int l, int cur){
    int r=cur;
    int ans=cur;

    while(r<numsSize&&l<=r){
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


int find_right(int* nums, int numsSize, int target, int r, int cur){
    int l=cur;
    int ans=cur;

    while(r<numsSize&&l<=r){
        int m=l+(r-l)/2;
        if(nums[m]==target){
            ans=m;
            l=m+1;
        }else{
            r=m-1;    
        }
    }

    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;

    int l=0,r=numsSize-1;
    int* ans=malloc(sizeof(int)*2);
    ans[0]=-1;
    ans[1]=-1;
    
    while(r<numsSize&&l<=r){
        int m=l+(r-l)/2;
        if(nums[m]==target){
            //keep find
            ans[0]=find_left(nums,numsSize,target,l,m);
            ans[1]=find_right(nums,numsSize,target,r,m);
            break;
        }else if(nums[m]>target){
            r=m-1;
        }else{
            l=m+1;
        }
    }

    return ans;
}
