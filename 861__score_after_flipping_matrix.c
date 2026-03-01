int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize;
    int n=gridColSize[0];
    int cnt1=0;
    int ans=0;

    for(int j=0;j<n;j++){
        cnt1=0;
        for(int i=0;i<m;i++){
            if(grid[i][j]==grid[i][0]){
               cnt1++; 
            }
        }
        
        //adjust real cnt1
        if(m-cnt1>cnt1){
            cnt1=m-cnt1;
        }

        ans+=cnt1*(1<<(n-1-j));
    }
    return ans;
}
