/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize=(n+1);
    int* ans=malloc(sizeof(int)*(*returnSize));
    ans[0]=0;
    for(int i=1;i<(n+1);i++){
        ans[i]=ans[i>>1]+(i&1);
    }
    return ans;
}
