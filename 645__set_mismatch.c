/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ans=malloc(sizeof(int)*2);
    int* cnt=calloc(numsSize+1, sizeof(int));
    *returnSize=2;

    for(int i=0;i<numsSize;i++){
        cnt[nums[i]]++;
    }
    for(int i=1;i<=numsSize;i++){
        if(cnt[i]==0){
            ans[0]=i;
        }

        if(cnt[i]==2){
            ans[1]=i;
        }
    }

    ans[0]=ans[0]^ans[1];
    ans[1]=ans[1]^ans[0];
    ans[0]=ans[0]^ans[1];

    free(cnt);
    return ans;
}
