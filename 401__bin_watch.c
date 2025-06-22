/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans=malloc(sizeof(char*)*60*12);
    *returnSize=0;

    for(int h=0;h<12;h++){
        for(int m=0;m<60;m++){
            if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){
                char* this=malloc(6);
                snprintf(this, 6, "%d:%02d",h,m);
                ans[(*returnSize)++]=this;
            }
        }
    }
    return ans;
}
