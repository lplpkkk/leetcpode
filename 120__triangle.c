#define MIN(a,b) ((a<b)?a:b)


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {

    //  ------
    // ---------
    //from (last-1) layer, bottom-up
    int max_len=triangleColSize[triangleSize-1];
    int dp[max_len];


    for(int i=0;i<(max_len);i++){
        dp[i]=triangle[triangleSize-1][i];
    }

    for(int i=(triangleSize-2);i>=0;i--){//vertical tracking (i,i-1)    
        for(int j=0;j<triangleColSize[i];j++){//horizon update data to dp[]
            #if(0)
            if(j>0){
                printf("add (normal): %d\n",MIN(triangle[i][j],triangle[i][j-1]));
                dp[j]=dp[j]+MIN(triangle[i][j],triangle[i][j-1]);
            }else{//first element
                printf("add (first): %d\n",triangle[i][0]);
                dp[j]=dp[j]+triangle[i][0];
            }
            #endif
            dp[j]=triangle[i][j]+MIN(dp[j],dp[j+1]);
        }
    }

    return dp[0];
    
}
