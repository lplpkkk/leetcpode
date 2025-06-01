/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
 //    *ColSize
 // ============= 
 //              |
 //              | Size
 //              |

#if(0)
int cmp(const void* a, const void*b){
    return ( ((int**)a)[0][0] - ((int**)b)[0][0]);
}
#else
int cmp(const void* a, const void* b) {
    int* int_a = *(int**)a;
    int* int_b = *(int**)b;
    return int_a[0] - int_b[0];
}
#endif

void dump(int** ans, int size){
    int i,j;

    printf("size=%d\n",size);

    for(i=0;i<size;i++){
        printf("%dth group:\n",i);
        if(ans[i]){
            printf("    data=%d to %d\n",ans[i][0], ans[i][1]);
        }else{
            printf("    nothing\n");
        }
        
    }

    return;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 1) {
        int** ret = malloc(sizeof(int*));
        ret[0] = malloc(sizeof(int) * 2);
        ret[0][0] = intervals[0][0];
        ret[0][1] = intervals[0][1];
        *returnSize = 1;
        *returnColumnSizes = malloc(sizeof(int));
        (*returnColumnSizes)[0] = 2;
        return ret;
    }


    
    //dump(intervals,intervalsSize);
    //printf("[before qsort] init data dump done\n");

    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    //dump(intervals,intervalsSize);
    //printf("init data dump done\n");

    int** ans=malloc(sizeof(int*)*intervalsSize); // this is max possibility
    *returnSize=0;
    *returnColumnSizes=malloc(sizeof(int)*intervalsSize);

    int* first = malloc(sizeof(int) * 2);
    first[0] = intervals[0][0];
    first[1] = intervals[0][1];
    ans[0] = first;
    *returnSize = 1;
    (*returnColumnSizes)[0] = 2;


    //      |____|
    //              |+++|

    #if(0)
    for(int i=1;i<intervalsSize;i++){

        // check lower bound
        if(intervals[i][0]>tmp[1]){
            //low>cur_max, need to malloc new
            int* this_interval=malloc(sizeof(int)*2);
            this_interval[0]=intervals[i][0];
            this_interval[1]=intervals[i][1];

            ans[*returnSize]=this_interval;
            (*returnSize)++;
            
            tmp[0]=intervals[i][0];
            tmp[1]=intervals[i][1];

        }else if(intervals[i][1]>tmp[1]){
            tmp[1]=intervals[i][1];
        }

        if(intervals[i][0]<tmp[0]){
            tmp[0]=intervals[i][0];
        }

        //check higher bound
        if(intervals[i][1]>tmp[1]){
            tmp[1]=intervals[i][1];
        }
        
    }   
    #endif
    for (int i = 1; i < intervalsSize; i++) {
        int* last = ans[*returnSize - 1];

        if (intervals[i][0] > last[1]) {
            int* new_intv = malloc(sizeof(int) * 2);
            new_intv[0] = intervals[i][0];
            new_intv[1] = intervals[i][1];
            ans[*returnSize] = new_intv;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else if (intervals[i][1] > last[1]) {
            last[1] = intervals[i][1];
        }
}

    //dump(ans,intervalsSize);

    return ans;
}
