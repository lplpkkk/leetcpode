/*
int find_msb_idx(int v){
    //this is for u32
    //binary seach the idx
    int l=0;
    int r=31;
    int m=(l+r)/2;
    while (!(v>=(1<<m)&&v>=(1<<(m+1)))){
        if(v<(1<<m)){
            l=m;
        }else{
            r=m;
        }
        m=(l+r)/2;
    }
    return m;
}

double champagneTower(int poured, int query_row, int query_glass){
    int msb_idx=find_msb_idx(pourd);
    if (query_row<msb_idx) return 1.0;
    if (query_row>(msb_idx+1)) return 0.0;
    double left=pourd-(1<<(msb_idx+1)-1);

    return (left/(1<<(msb_idx+1)));
}
*/

#define MIN(a,b) (((a)<(b))?(a):(b))

double champagneTower(int poured, int query_row, int query_glass){
    //0 to 100 layer
    double dp[101][101];

    memset(dp,0,sizeof(dp));
    dp[0][0]=poured;

    for(int i=0;i<query_row;i++){
        for(int j=0;j<=i;j++){
            if (dp[i][j]>1.0){
                double overflow=(dp[i][j]-1)*0.5;
                dp[i+1][j]+=overflow;
                dp[i+1][j+1]+=overflow;
            }
        }
    }

    return MIN(1.0,dp[query_row][query_glass]);
}
