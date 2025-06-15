int removeDuplicates(int* nums, int numsSize) {
    int cur_cnt=0;
    int cur_val= INT_MAX;
    int cur_idx=0;

    for(int i=0;i<numsSize;i++){
        
        if(nums[i]!=cur_val){
            cur_val=nums[i];
            nums[cur_idx]=cur_val;
            cur_idx++;

            cur_cnt=1;//first one
        }else{
            cur_cnt++;
            if(cur_cnt>2){
                //replaced by next val
            }else{
                nums[cur_idx]=cur_val;
                cur_idx++;
            }
        }
    }
    return cur_idx;
}
