int cmp(const void* a, const void* b){
    return ((*((int*)b)) -*((int*)a));
}

bool dfs(int* nums, int numsSize, int index, int* buckets, int k, int target) {

    if(index==numsSize){
        return true;
    }

    for(int i=0;i<k;i++){
        if(buckets[i]+nums[index]>target) continue;

        buckets[i]+=nums[index];
        if(dfs(nums,numsSize,index+1,buckets,k,target)){
            return true;
        }
        buckets[i]-=nums[index];
        
        if(buckets[i]==0) break;
    }
    return false;
}




bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int total=0;

    for(int i=0;i<numsSize;i++){
        total+=nums[i];
    }

    if(total%k){
        return 0;
    }   

    int target=total/k;
    int * cnt=malloc(sizeof(int)*k);

    if(nums[0]>target){
        return false;
    }

    int* buckets=calloc(k,sizeof(int));
    bool result=dfs(nums,numsSize,0,buckets,k,target);
    free(buckets);

    return result;
}
