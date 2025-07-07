bool hasAlternatingBits(int n) {
    bool last=n&1;
    n>>=1;

    while(n){
        if(last==(n&1)){
            return false;
        }
        last=n&1;
        n>>=1;
    }
    return true;
}
