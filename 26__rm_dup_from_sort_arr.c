int removeDuplicates(int* nums, int numsSize) {
    int l=0;
    //int r=0; --> use i 
    int last=nums[0];

    for(int i=1;i<numsSize;i++){
        if(nums[i]!=last){
            last=nums[i];
            nums[l+1]=nums[i];
            l=l+1;
        }else{
            // do nothing
        }    
    }
    return (l+1);
}
