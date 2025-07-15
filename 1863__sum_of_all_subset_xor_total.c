int subsetXORSum(int* nums, int numsSize) {
    int total_case=(1<<numsSize);
    int ans=0;

    for(int i=0;i<total_case;i++){
        int tmp=0;
        for(int j=0;j<numsSize;j++){
            if((i>>j)&1){
                tmp^=nums[j];
            }
        
        }
        ans+=tmp;
    }
    return ans;
}
