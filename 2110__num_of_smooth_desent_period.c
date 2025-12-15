long long getDescentPeriods(int* prices, int pricesSize) {
    long long ans=1;
    long long cur=1;

    if(pricesSize==0){
        return 0;
    }

    for(int i=1;i<(pricesSize);i++){
        if(prices[i]==(prices[i-1]-1)){
            cur++;    
        }else{
            cur=1;
        }
        ans+=cur;
    }
    return ans;
}
