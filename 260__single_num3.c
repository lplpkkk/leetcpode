/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#if(0)
int cmp(const void* a, const void* b){
    return ( (long) (*(int*)a ) -  (long) (*(int*)b) );
}
#endif
int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}


int* singleNumber(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int *ans=malloc(sizeof(int)*2);
    int idx=0;
    int this_cnt=1;
    *returnSize=2;

    if(numsSize==2){
        ans[0]=nums[0];
        ans[1]=nums[1];
        return ans;
    }


    int last=nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=last){
            if(this_cnt==1){
                ans[idx]=last;
                idx++;
                if(idx==2){
                    break;
                }
            }
            this_cnt=1;
             
        }else{
            this_cnt++;
        }

        last=nums[i];
    }

    if (this_cnt == 1 && idx < 2) {
        ans[idx++] = last;
    }

    return ans;
}
