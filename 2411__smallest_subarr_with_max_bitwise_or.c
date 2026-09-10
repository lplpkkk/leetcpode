/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX(a,b) ( (a>b)?(a):(b))

int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int* ans=malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    
    int last[32];
    for(int i=0;i<32;i++) last[i]=-1;

    for(int i=numsSize-1;i>=0;i--){
        int end=i;

        for(int bit=0;bit<32;bit++){
            if(nums[i]&(1UL<<bit)){
                last[bit]=i;
            }

            if(last[bit]!=-1){
                end=MAX(end,last[bit]);
            }
        }

        ans[i]=end-i+1;
    }

    return ans;
    
}
