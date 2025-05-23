#define MAX(a,b) ( (a>b)?a:b )
int dp[100];

int rob(int* nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    if(numsSize==1){
        return nums[0];
    }

    dp[0]=nums[0];
    dp[1]=MAX(nums[0],nums[1]);
    
    for(int i=2;i<numsSize;i++){
        dp[i]=MAX(dp[i-1],dp[i-2]+nums[i]);
    }

    return dp[numsSize-1];
}
