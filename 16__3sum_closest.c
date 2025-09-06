int cmp(const void* a, const void* b){
    //return (*(int*)a - *(int*)b);
    int x=*(int*)a, y=*(int*)b;
    return (x>y)-(x<y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int global_closest=(nums[0]+nums[1]+nums[2]);

    for(int i=0;i<(numsSize-2);i++){
        int tmp=nums[i];
        int* l=nums+i+1;
        int* r=nums+numsSize-1;

        while(l<r){
            int closest=(tmp+*l+*r);
            long long d1=(long long)closest - target;
            long long d2=(long long)global_closest - target;
            if(llabs(d1)<llabs(d2)){
                global_closest=closest;
            }

            if((tmp+*l+*r)==target){
                return target;
            }else if((tmp+*l+*r)<target){
                l++;
            }else if((tmp+*l+*r)>target){
                r--;
            }
            closest=tmp+*l+*r;
        }
        
    }
    return global_closest;
}
