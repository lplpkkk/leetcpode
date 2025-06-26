/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* ans=malloc(sizeof(bool)*numsSize);
    *returnSize=numsSize;

    int tmp=0;
    for(int i=0;i<numsSize;i++){
        tmp=( (tmp<<1) |nums[i])%5;
        if((tmp%5)==0){
            ans[i]=true;
        }else{
            ans[i]=false;
        }
    }
    return ans;
}
