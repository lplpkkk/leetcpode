/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize=1<<n;
    int* ans=malloc(sizeof(int)*(*returnSize));
    
    
    for(int i=0;i<(*returnSize);i++){
        ans[i]=(i)^((i)>>1);
    }
    return ans;
    
}
