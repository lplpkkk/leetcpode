int findComplement(int num) {
    int idx=0;
    long long mask=1;
    while(mask<=num){
        mask<<=1;
    }
    return ((mask)-1)^num;
}
