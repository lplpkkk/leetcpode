
void rev(int* num, int l, int r){
    while(l<r){
        num[l]=num[l]^num[r];
        num[r]=num[l]^num[r];
        num[l]=num[l]^num[r];
        l++;
        r--;
    }
}


void nextPermutation(int* nums, int numsSize) {
    /* last, and last last element */
    int i=numsSize-2;
    /* find this pivot point */
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }

    if(i>=0){
        int j=numsSize-1;
        
        while(nums[j]<=nums[i]){
            j--;
        }
        /* swap */
        nums[j]=nums[i]^nums[j];
        nums[i]=nums[i]^nums[j];
        nums[j]=nums[i]^nums[j];
    }

    rev(nums,i+1,numsSize-1);    
}
