/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int tmp=0;
    int* ans=malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;

    for(int i=0;i<numsSize;i++){
        int found=0;
         for (int x = 0; x < nums[i]; ++x) {
            if((x|(x+1))==nums[i]){
                found=1;
                ans[i]=x;
                break;
            }
         }
         if(!found) ans[i]=-1;
    }    

    return ans;
}
