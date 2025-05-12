#if(0)
unsigned long long fac(int n){
    int ans=1;

    if(n<=1){
        return 1;
    }else{
        for(int i=2;i<=n;i++){
            ans*=i;        
        }
    }

    return ans;
    
}

int comb(int m, int n){
    int tmp;
    if(m<n){
        tmp=m;
        m=n;
        n=tmp;
    }
    return fac(m)/(fac(n)*fac(m-n));
}


int climbStairs(int n) {
    int ways=0;
    int max_2_step=0;
    int cur_2step=0;
    int cur_1step=0;
    int sum=0;

    int extra=(n%2)?1:0;
    max_2_step=n/2;

    for(int i=0;i<=max_2_step;i++){
        cur_2step=i;
        cur_1step=(n-2*i);
        
        sum+=comb(cur_2step+cur_1step,cur_1step);        
    }

    return sum;
}
#endif

int climbStairs(int n) {
    // f(n)=f(n-1)+f(n-2)
    int a=1,b=2,temp;
    if(n<=2){
        return n;
    }
    for(int i=3;i<=n;i++){
        temp=a+b;
        a=b;
        b=temp;
    }
    return temp;
}
