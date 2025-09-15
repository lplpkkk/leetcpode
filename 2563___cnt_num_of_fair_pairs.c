int cmp(const void* a, const void* b){
    int x= *(int*)a;
    int y= *(int*)b;
    return (x>y)-(y>x);
}

long long cnt_all(int* nums, int l, int r, int lim){
    long long ans=0;

    while(l<r){
        if((nums[l]+nums[r])<=lim){
            ans+=(r-l);
            l++;
        }else{
            r--;
        }
    }
    return ans;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    long long ans=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int l=0, r=numsSize-1;
    
    #if(0)
    // find lower_bound val idx
    int lb_idx=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>lower){
            lb_idx=((i-1)>=0)?(i-1):0;
            break;
        }
    }
    #endif

    return cnt_all(nums,0,numsSize-1,upper) - cnt_all(nums,0,numsSize-1,lower-1);
}
