int _dp[100][100];

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
     int (*dp)[100] = _dp;
     for(int i=0;i<obstacleGridSize;i++){
        for(int j=0;j<obstacleGridColSize[0];j++){

            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;    
            }
            else{
                if((i==0)&&(j==0)){
                    dp[i][j]=1;
                }else if((i==0)||(j==0)){
                    dp[i][j]=(i==0)?dp[i][j-1]:dp[i-1][j];
                    //dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            } 
            
        }
     }

     return dp[obstacleGridSize-1][obstacleGridColSize[0]-1];

}
