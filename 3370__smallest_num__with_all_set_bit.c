int smallestNumber(int n) {
    int msb=0;

    while(n){
        msb++;//3
        n>>=1;
    }

    return ((1<<(msb))-1);
}
