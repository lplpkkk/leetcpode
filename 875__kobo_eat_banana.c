#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int get_max(int* piles, int sz){
    int max=-1;
    for(int i=0;i<sz;i++) max=MAX(max,piles[i]);
    return max;
}

bool chk(int* piles, int pilesSize, int h, int k){
    int cnt=0;
    for(int i=0;i<pilesSize;i++){
        cnt+=((piles[i]+k-1)/k);
        if(cnt>h) return false;
    }
    return true;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max=get_max(piles,pilesSize);
    int l=1,r=max;
    int ans=max;

    while(l<=r){
        int k=l+(r-l)/2;
        if(chk(piles,pilesSize,h,k)){
            //this bite can be smaller
            r=k-1;
            ans=MIN(ans,k);
        }else{
            l=k+1;
        }
    }

    return ans;
}
