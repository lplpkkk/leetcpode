unsigned int mask_shift[]={2,3,5,7,11,13,17,19,23,29,31};

unsigned int mask_helper(unsigned int* shft,int size){
    unsigned int ans=0;
    for(int i=0;i<size;i++){
        ans|=(1U<<shft[i]);
    }
    return ans;
}

int countPrimeSetBits(int left, int right) {
    //possible prime=2,3,5,7,11,13,17,19,23,29,31
    int size=sizeof(mask_shift)/sizeof(mask_shift[0]);
    unsigned int mask=mask_helper(mask_shift,size);
    int ans=0;

    for(int i=left;i<=right;i++){
        int bits=__builtin_popcount(i);
        if (((mask>>bits)&1)==1){
            ans+=1;
        }
    }
    return ans;
}
