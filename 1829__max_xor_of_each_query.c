/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #if(0) //TLE
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int* ans=malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;

    for(int i=0;i<numsSize;i++){//for ans
        int xor_val=0;

        for(int j=0;j<numsSize;j++){
            xor_val^=nums[j];    
        }
        
        ans[i]=(~xor_val)& ((1<<maximumBit)-1);
        nums[numsSize-1-i]=0;
    }

    return ans;
}

#endif


int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int* ans=malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    int xor_val=0;

    for(int i=0;i<numsSize;i++){
        xor_val^=nums[i];    
    }

    int mask=(1u<<maximumBit)-1;
    for(int i=0;i<numsSize;i++){
        ans[i]=xor_val^mask;
        xor_val^=nums[numsSize-1-i];
    }
    

    return ans;
}
