int removeElement(int* nums, int numsSize, int val) {

    //corner handling
    if(nums==NULL){
        return 0;
    }
    
    int replace_idx=0;

    for(int i=0;i<numsSize;i++){
        if(val!=nums[i]){
            nums[replace_idx++]=nums[i];
        }else{
        }
    }

    return replace_idx;
}
