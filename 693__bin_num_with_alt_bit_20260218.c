bool hasAlternatingBits(int n) {
    unsigned tmp=n^(n>>1);
    return ((tmp&(tmp+1))==0);
}
