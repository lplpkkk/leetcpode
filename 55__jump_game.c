#if(0)
int sel_max(int* nums, int cur){
    int max=0;
    for(int i=0;i<nums[cur];i++){
        if(nums[cur-i]>max){
            max=nums[i+cur];
        }
    }
    return max;
}

bool canJump(int* nums, int numsSize) {
    int i=0;
    int* step=nums;
    int cur_step=0;
    int next_step=0;
    int max_step=0;

    if(nums==NULL){
        return true;
    }

    while(cur_step<numsSize){
        // handle always fail case
        max_step=sel_max(nums,cur_step);

        if(max_step==0){
            if(numsSize==1){
                return true;
            }else{
                return false;
            }            
        }

        printf("max step=%d, cur=%d\n",max_step, cur_step);
        
        if( ((numsSize-1-cur_step)==0) 
        || (max_step >= (numsSize-1-cur_step)) ) {
            return true;
        }

        cur_step+=max_step;

    }
    
    if(cur_step==numsSize){
        return true;
    }else{
        printf("fail 2\n");
        return false;
    }
    
}
#endif



bool canJump(int* nums, int numsSize) {
    int max=0;
    
    if(nums==NULL){
        return true;
    }

    for(int i=0;i<numsSize;i++){
        if(i>max){
            return false;
        }

        if((i+nums[i])>max){
            max = i+nums[i];
        }
        
    }

    return true;
}
