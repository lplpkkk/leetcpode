/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct{
    int start;
    int end;
}interval;

int cmp(const void* a, const void* b){
    int* p1= *(int**)a;
    int* p2= *(int**)b;
    
    return p1[0]-p2[0];
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals,intervalsSize,sizeof(interval),cmp);

    int** ans=malloc(sizeof(int*)*intervalsSize);
    *returnColumnSizes=malloc(sizeof(int)*intervalsSize);

    //push the first
    int count=0;
    ans[count]=malloc(sizeof(int)*2);
    ans[count][0]=intervals[0][0];
    ans[count][1]=intervals[0][1];
    (*returnColumnSizes)[count]=2;
    count++;

    for(int i=1;i<intervalsSize;i++){
        //check overlap
        if(intervals[i][0]<=ans[count-1][1]){
            if(intervals[i][1]>ans[count-1][1]){
                ans[count-1][1]=intervals[i][1];
            }else if(intervals[i][0]<ans[count-1][0]){
                ans[count-1][0]=intervals[i][0];
            }
        }else{
            ans[count]=malloc(sizeof(int)*2);
            ans[count][0]=intervals[i][0];
            ans[count][1]=intervals[i][1];
            (*returnColumnSizes)[count]=2;
            count++;
            
        }
    }

    *returnSize=count;

    return ans;
}
