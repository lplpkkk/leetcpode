int cmp(const void* a, const void*b){
    return (*(int*)a - *(int*)b);
}

void dbg(int *nums, int len){
    for(int i=0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}
int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    //dbg(nums,numsSize);
    return nums[(numsSize/2)];
}
