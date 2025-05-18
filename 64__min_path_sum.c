#define MIN(a,b) ((a<b)?a:b)
int _dp[200][200];

int get_val(int i, int j,int (*src)[200]){
    
    return ((i<0)||(j<0))?(INT_MAX-200):src[i][j];
}


//13:27
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    //top-down
    int (*dp)[200]= _dp;

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if((i==0)&&(j==0)){
                dp[i][j]=grid[0][0];
            }else{
                dp[i][j]=MIN(get_val(i-1,j,dp),get_val(i,j-1,dp))+grid[i][j];        
            }
            
        }
    }

    return dp[gridSize-1][gridColSize[0]-1];
    

}
