bool is_prime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    if((n%2)==0) return false;

    int x=(int)sqrt(n);
    for(int i=3;i<=x;i+=2){
        if((n%i)==0) return false;
    }
    return true;
}

int countPrimeSetBits(int left, int right) {
    int ans=0;
    int tmp;

    for(int i=left;i<=right;i++){
        tmp=__builtin_popcount(i);
        if(is_prime(tmp)){
            ans++;
        }    
    }    
    return ans;
}
