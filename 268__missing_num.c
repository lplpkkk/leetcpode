int missingNumber(int* nums, int numsSize) {
    int total=(numsSize+1)*numsSize/2;
    //printf("total=%d\n",total);

    for(int i=0;i<numsSize;i++){
        //printf("elem=%d\n",nums[i]);
        total-=nums[i];
    }
    return total;
}
