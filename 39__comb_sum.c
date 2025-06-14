/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int* returnColumnSizes,int* path, int pathSize,int** res,int start) {
    if(target==0){
        int *comb=malloc(sizeof(int)*pathSize);
        memcpy(comb,path,sizeof(int)*pathSize);
        res[*returnSize]=comb;
        returnColumnSizes[*returnSize]=pathSize;
        (*returnSize)++;
        return;
    }
    
    for(int i=start;i<candidatesSize;i++){
        if (candidates[i] > target) continue;

        path[pathSize]=candidates[i];

        dfs(candidates,candidatesSize,(target -candidates[i]),
            returnSize,returnColumnSizes,
            path, pathSize+1,res,i);
    }
    
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans=malloc(sizeof(int*)*1000);
    *returnColumnSizes=malloc(sizeof(int)*1000);
    int* path=malloc(sizeof(int*)*1000);
    *returnSize=0;

    dfs(candidates,candidatesSize,target,returnSize,*returnColumnSizes,path,0,
        ans,0);
    
    return ans;
}
