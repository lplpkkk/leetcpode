
bool xorGame(int* nums, int numsSize) {

    bool ans=0;
    int xor_v=0;

    for(int i=0;i<numsSize;i++){
        xor_v^=nums[i];
    }

    return (xor_v==0 || ((numsSize&1)==0));
}
