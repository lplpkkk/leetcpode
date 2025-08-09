/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if(0)
int cmp(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return x - y; // 先依數值排序
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize=arrSize;

    qsort(arr,arrSize,sizeof(int),cmp);
    int* n1=malloc(sizeof(int)*arrSize);
    int max_n1=0;

    for(int i=0;i<arrSize;i++){
        n1[i]=__builtin_popcount(arr[i]);
        if(n1[i]>max_n1){
            max_n1=n1[i];
        }
    }

    int* ans=malloc(sizeof(int)*arrSize);
    /* use a while loop to put from n1=0 to n1=max_n1 to ans */
    int idx=0;
    for(int i=0;i<=max_n1;i++){
        for(int j=0;j<arrSize;j++){
            if(n1[j]==i){
                ans[idx++]=arr[j];
            }
        }
    }

    free(n1);
    return ans;
}
#endif

int cmpBits(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    int px = __builtin_popcount(x);
    int py = __builtin_popcount(y);

    if (px != py) return px - py;
    return x - y;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmpBits);
    return arr; // 原地排序，不用額外 malloc
}
