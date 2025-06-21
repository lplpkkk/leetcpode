#if(0)
int kthGrammar(int n, int k) {
    // get n-th data
    int data=0;
    //1 -->2^0
    //2 -->2^1
    //3 -->2^2
    //n -->2^(n-1) bit
    int tmp=data;
    n=n-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if((tmp>>j)&1){
                //replace with '10'
                //from 1<<x to 1<<(2*x)
                //mask=~(1<<x)|
                data=(data&~(1<<j))|(1<<(2*j));
            }else{
                // replace with '01'
                data|=(1<<2*j);
            }
        }
        tmp=data;
    }

    return (data>>k)&1;
}
#endif

int kthGrammar(int n, int k) {
    if(n==1){
        return 0;
    }

    if(k&1){
        return kthGrammar(n-1, (k+1)/2);
    }else{
        return !kthGrammar(n-1,k/2);
    }
}
