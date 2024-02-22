

void __shift(int *p, int offset, int size){
    int* tmp = malloc(sizeof(int)*size);

    memcpy(tmp,p+offset,sizeof(int)*size);
    memcpy(p+offset+1,tmp,sizeof(int)*size);
    memset(p+offset,0,sizeof(int)*1);

    free(tmp);
}

void insert(int* t, int size, int in){
    
    unsigned char i = 0;

    for(i=0;i<size;i++){
        if(in<=*(t+i)){
            __shift( t,i,size-i);
            *(t+i)=in;
            return;
        }
    }
    
    *(t+size)=in;

    return;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* pAns = malloc(sizeof(int)*(m+n));
    
    pAns = nums1;
    
    /* merge array 2 to array1 */
    unsigned char i = 0;

    for(i=0;i<n;i++){
        insert(pAns, m+i, *(nums2+i));    
    }
    
    nums1 = pAns;
}
