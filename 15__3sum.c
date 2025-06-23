/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void *b){
    return ( *(int*)a) - ( *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int target=0;
    int cap=30000;
    int* l, *r;
    int** ans=malloc(sizeof(int*)*cap);
    
    *returnSize=0;
    (*returnColumnSizes)=malloc(sizeof(int)*cap);

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i=0;i<numsSize-2;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        target=nums[i];
        //l=(nums+i+1);
        //r=(nums+numsSize-1);

        int left = i + 1;
        int right = numsSize - 1;

        while(left<right){
            if((nums[left]+nums[right]+target)==0){
                int* this=malloc(sizeof(int)*3);
                this[0]=nums[i];
                this[1]=nums[left];
                this[2]=nums[right];
                ans[*returnSize]=this;
                (*returnColumnSizes)[*returnSize]=3;
                *returnSize+=1;

                while(left<right && nums[left]==nums[left+1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
                
                left++;
                right--;

            }else if((nums[left]+nums[right]+target)<0){
                left++;
            }else{ //>0
                right--;
            }
        }
    }

    return ans;
}
