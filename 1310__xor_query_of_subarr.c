/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if(0)//bruce force
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* ans=malloc(sizeof(int)*queriesSize);
    *returnSize=queriesSize;
    
    for(int i=0;i<queriesSize;i++){
        int tmp=arr[queries[i][0]];
        for(int j=(queries[i][0]+1);j<=queries[i][1];j++){
            tmp^=arr[j];
        }
        ans[i]=tmp;
    }

    return ans;
}
#endif

int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* ans=malloc(sizeof(int)*queriesSize);
    *returnSize=queriesSize;

    int* prefix=malloc(sizeof(int)* (arrSize+1));
    prefix[0]=0;

    for(int i=0;i<arrSize;i++){
        prefix[i+1]=prefix[i]^arr[i];
    }

    for(int i=0;i<queriesSize;i++){
        int l=queries[i][0];
        int h=queries[i][1];
        ans[i]=prefix[h+1]^prefix[l];
    }

    free(prefix);
    return ans;
}
