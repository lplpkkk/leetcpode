/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** ans;
int* collen;
int* tmp;
int cnt;

void dfs(int* nums,int nums_max, int cur_idx, int cur_len){
    if(cur_len>=2){
        ans[cnt]=(int*)malloc(cur_len*sizeof(int));
        memcpy(ans[cnt],tmp,cur_len*sizeof(int));
        collen[cnt]=cur_len;
        cnt++;
    }
    int used[201]={0};
    
    for(int i=cur_idx;i<nums_max;i++){
        if(used[nums[i]+100]==1){
            continue;
        }
        
        tmp[cur_len]=nums[i];
        used[nums[i]+100]=1;

        if(cur_len==0||nums[i]>=tmp[cur_len-1]){
            dfs(nums,nums_max,i+1,cur_len+1);
        }
    }
    return;
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int max=33000;//2^15=2^5*2^10=32*1024
    cnt=0;
    ans=malloc(sizeof(int*)*max);
    collen=malloc(sizeof(int)*max);
    tmp=malloc(sizeof(int)*numsSize);

    dfs(nums,numsSize,0,0);
    *returnSize=cnt;
    *returnColumnSizes=collen;

    free(tmp);
    return ans;
}
