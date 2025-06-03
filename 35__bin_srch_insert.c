int searchInsert(int* nums, int numsSize, int target) {
    int l=0;
    int r=numsSize-1;
    int tar_idx;

    while(l<=r){
        tar_idx=(l+r)/2;
        if(nums[tar_idx]==target){
            return tar_idx;
        }

        if(nums[tar_idx]<target){
            l=(tar_idx+1);
        }else{
            r=(tar_idx-1);
        }
    }
    //0,3..1
    //1,6..3

    //-->
    //1.3..2
    //     5

    //0.1..0

    return l;
}
