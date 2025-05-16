int jump(int* nums, int numsSize) {
    int step=0;
    int max=0;
    int end=0;

    if((*nums>=0)&& (numsSize==1)){
        return 0;
    }

    for(int i=0;i<(numsSize-1);i++){
        if(max>=i){//reachable
            
            max=(i+nums[i] >max)?(i+nums[i]):max;

            if(i==end){
                step++;
                end=max;
                if(max>=(numsSize-1)){
                    return step;
                }
            }
        }
    }

    return -1;
}
