int maxSubArray(int* nums, int numsSize) {
    int sum=0;
    int max=0;
    int total=0;

    if(nums==NULL){
        return 0;
    }

    sum=max=nums[0];
    

    for(int i=1;i<numsSize;i++){
        
        if(sum<0){
            sum=nums[i];
        }else{
            sum+=nums[i];
        }

        if(sum>max){
            max=sum;
        }
    }

    return max;
}
