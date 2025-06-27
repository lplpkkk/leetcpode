#if(0)
int totalHammingDistance(int* nums, int numsSize) {
    int ans=0;
    for(int i=0;i<numsSize;i++){
        for(int j=(i+1);j<numsSize;j++){
            ans+=( __builtin_popcount(nums[i]^nums[j]));
        }
    }
    return ans;
}
#endif

int totalHammingDistance(int* nums, int numsSize) {
    int zero_cnt=0;
    int ans=0;

    for(int i=0;i<32;i++){
        zero_cnt=0;

        for(int j=0;j<numsSize;j++){
            if(((nums[j]>>i)&1)){
                zero_cnt++;
            }
        }
        ans+=(numsSize-zero_cnt)*zero_cnt;

    }
    return ans;
}
