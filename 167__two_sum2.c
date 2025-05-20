/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int l_idx=0;
    int h_idx=numbersSize-1;
    int* ans=malloc(sizeof(int)*2);
    int sum=0;

    *returnSize=2;

    while(l_idx<h_idx){
        sum=(numbers[l_idx]+numbers[h_idx]);
        
        //printf("sum=%d, l=%d, h=%d\n",sum, l_idx, h_idx);

        if(sum==target){
            ans[0]=l_idx+1;
            ans[1]=h_idx+1;
            //printf("find --> [0]=%d, [1]=%d\n",ans[0], ans[1]);
            return ans;

        }else if (sum>target){
            h_idx--;
        }else{
            l_idx++;
        }

    }

    return ans;
}
