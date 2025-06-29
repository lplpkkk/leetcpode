#if(0)
#define MIN(x,y) ((x<y)?x:y)

int maximumStrongPairXor(int* nums, int numsSize) {
    int max=0;

    for(int i=0;i<numsSize;i++){
        for(int j=i;j<numsSize;j++){
            if(abs(nums[i]-nums[j])<=MIN(nums[i],nums[j])){
                if((nums[i]^nums[j])>max){
                    max=nums[i]^nums[j];
                }
            }
        }
    }    
    return max;
}
#endif


//might use trie way to optimize
