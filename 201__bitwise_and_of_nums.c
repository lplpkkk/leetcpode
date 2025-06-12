
#if(0)
//5--> b'101
//6--> b'100
//7--> b'111

int rangeBitwiseAnd(int left, int right) {
    int result=-1;
    int i=0, j=0;

    for(i=0;i<32;i++){
        for(j=left;j<=right;j++){
            if(result&(1>>i)==0){
                continue;
            }
            if (!(j&(1u<<i))){
                // val=j, doesnt have this bit
                result&= (~(1u>>i));
            }
        }    
    }    
    return result;
}
#endif

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

