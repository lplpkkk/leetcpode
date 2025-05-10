int cmp(const void* a, const void* b){
   return (*(int*)a-*(int*)b);
}

void _dbg_arr(int* s, int len){
    for(int i=0;i<len;i++){
        printf(" %d ", *(s+i));
    }
    printf("\n");
}

#define MIN(a,b) (a<b)?a:b
#define MAX(a,b) (a>b)?a:b

int hIndex(int* citations, int citationsSize) {

    if(citations==NULL){
        return 0;
    }

    qsort(citations, citationsSize, sizeof(int), cmp);
    //_dbg_arr(citations, citationsSize);
    printf("citationsSize=%d\n",citationsSize);

    int ans=0;
    //                |
    // example: 0  1  3  5  6  
    //             |
    // example: 1  1. 3    
    for(int i=0;i<citationsSize;i++){
        // check (how many larger) is bigger than citation value
        //if((citationsSize-i)>=*(citations+i)){
        if(*(citations+i)>=(citationsSize-i)){
            //ans=*(citations+i);
            //printf("i:%d, left:%d, val:%d\n", i, citationsSize-i,*(citations+i));
            //ans=MIN((citationsSize-i)+1,*(citations+i));
            return (citationsSize-i);
        }
    }

    return ans;
}
