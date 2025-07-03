bool pass(int* nums, int numsSize){
    for(int i=1;i<numsSize;i++){
        if( nums[i] < nums[i-1]){
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int* tmp=malloc(sizeof(int)*numsSize);
    memcpy(tmp,nums,sizeof(int)*numsSize);
    int step=0;
    int n=numsSize;

    while(!pass(tmp,n)){
        int min_sum=tmp[0]+tmp[1];
        int idx=0;
        for(int i=1;i<n-1;i++){
            int s=tmp[i]+tmp[i+1];
            if(s<min_sum){
                min_sum=s;
                idx=i;
            }
        }
        tmp[idx]=min_sum;
        for(int j=idx+1;j<n-1;j++){
            tmp[j]=tmp[j+1];
        }
        n--;
        step++;
    }
    free(tmp);
    return step;

}
