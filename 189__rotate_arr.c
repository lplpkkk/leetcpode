void _debug(int* arr, int size){
    for(int i=0;i<size;i++){
        printf(" %d ", *(arr+i));
    }
    printf("\n");
}

void rotate(int* nums, int numsSize, int k) {

    int* tmp=malloc(k*sizeof(int));
    k=k%numsSize;
    
    if(numsSize<2){
        return ;
    }
    memcpy(tmp, nums+numsSize-k,k*sizeof(int));
    memmove(nums+k,nums,(numsSize-k)*sizeof(int));
    memcpy(nums,tmp,k*sizeof(int));
    free(tmp);
}
