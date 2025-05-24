
#if(0)
typedef struct node{
    int last_max;
    int len; 
} node;

int dp[2500];

int lengthOfLIS(int* nums, int numsSize) {
    node _node[numsSize];
    int all_max_len=-1;
    

    if(numsSize==1){
        return 1;
    }

    //init 
    for(int i=0;i<numsSize;i++){
        _node[i].len=1;
        _node[i].last_max=nums[i];
        dp[i]=0;    
    }    

    for(int i=0;i<numsSize;i++){
        #if(0)
        for(int j=(i+1);j<numsSize;j++){
            if(nums[j]>_node[i].last_max){
                _node[i].last_max=nums[j];
                _node[i].len+=1;
            }
        }
        #endif

        for(int j=numsSize-2;j>=(i+1);j++){
            if(nums[j+1]>=nums[j]){
                dp[j]=dp[j+1]+1;   
            }           
        }

        if(dp[i+1]>all_max_len){
            all_max_len=dp[i];
        }
    }

    return all_max_len;
}
#endif

int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    int max=-1;

    for(int i=0;i<numsSize;i++){
        dp[i]=1;

        for(int j=0; j<i;j++){
            if((nums[i]>nums[j])
            && (dp[i]<dp[j]+1))

            {
                dp[i]=dp[j]+1;
            }
        }

        if(dp[i]>max){
            max=dp[i];
        }    
    }
    return max;
}
