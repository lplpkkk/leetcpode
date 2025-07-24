int bitwiseComplement(int n) {
    if(n==0) return 1;

    int mask=0;
    int tmp=n;

    while(tmp){
        mask=(mask<<1)|1;
        tmp>>=1;
    }

    return n^mask;
}
