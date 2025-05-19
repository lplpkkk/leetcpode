/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // the only carry case is the digit 9
    // lets trace from the last one
    int digit=0;
    for(int i=digitsSize-1;i>=0;i--){
        if((digits[i])==9){
            //keep carrying
            digit++; 
        }else{
            break;//no need
        }
    }

    if(digit==digitsSize){
        *returnSize=digitsSize+1;
    }else{
        *returnSize=digitsSize;
    }

    int *ans=malloc(sizeof(int)*(*(returnSize)));
    memcpy(ans,digits,digitsSize*sizeof(int));
    for(int i=((*returnSize)-digit);i<(*returnSize);i++){
        ans[i]=0;
    }
    ans[((*returnSize)-digit)-1]= ((ans[((*returnSize)-digit)-1])==9)?1:(ans[((*returnSize)-digit)-1]+1);
    
    return ans;
}
