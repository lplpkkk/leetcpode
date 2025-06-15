/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return (*(int*)a-*(int*)b);
}

void dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes,
         int** ans, int* path, int path_size, int start){

    int* subset=malloc(sizeof(int)*path_size);
    memcpy(subset,path,sizeof(int)*path_size);
    
    ans[*returnSize]=subset;
    (*returnColumnSizes)[*returnSize]=path_size;
    (*returnSize)++;


    for(int i=start;i<numsSize;i++){
        if(i>start && (nums[i]==nums[i-1])){
            continue;
        }
        path[path_size]=nums[i];
        dfs(nums,numsSize,returnSize,returnColumnSizes,
        ans,path,path_size+1,i+1);    
    }
    
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int **ans=malloc(sizeof(int*)*2000);
    *returnColumnSizes=malloc(sizeof(int)*2000);
    int *path=malloc(sizeof(int)*numsSize);
    *returnSize=0;

    qsort(nums,numsSize,sizeof(int),cmp);
    dfs(nums,numsSize,returnSize,returnColumnSizes,
        ans,path,0,0);

    return ans;
}


