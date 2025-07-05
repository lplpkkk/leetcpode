/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize){
    int size=1<<n;
    int* ans=malloc(sizeof(int)*size);
    *returnSize=size;

    for(int i=0;i<size;i++){
        ans[i]=i^(i>>1)^start;
    }

    return ans;
}
