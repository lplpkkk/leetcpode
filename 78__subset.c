/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int all_case=1<<numsSize;
    *returnSize=all_case;
    int** ans=malloc(sizeof(int*)*all_case);
    *returnColumnSizes = (int*)malloc(sizeof(int) * all_case);

    for(int i=0;i<all_case;i++){
        int *tmp=malloc(sizeof(int)*numsSize);
        int cur_idx=0;

        for(int j=0;j<numsSize;j++){
            if((i>>j)&1){
                tmp[cur_idx++]=nums[j];
            }
        }
        ans[i]=tmp;
        (*returnColumnSizes)[i]=cur_idx;
    }

    return ans;

}
