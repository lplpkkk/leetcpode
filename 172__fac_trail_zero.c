int trailingZeroes(int n) {
    int len=0;
    while(n>=5){
        n/=5;
        len+=n;
    }
    return len;
}
