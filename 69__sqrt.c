int mySqrt(int x) {
    long long ans,l=1,r=x/2;
    long long lb,ub;

    if((x==0)||(x==1)){
        return x;
    }

    
    while(l<=r){
        ans=(l+r)/2;
        lb=ans*ans;
        ub=(ans+1)*(ans+1);
        
        if ((x>=lb)&&(x<ub)){
            return ans;
        }else if(x<lb){
            //ans is too large
            r=ans-1;
        }else{
            l=ans+1;
        }

 
    }

    return -1;
}
