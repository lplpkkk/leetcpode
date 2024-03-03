/*
        m
    ----------
    |
 n  |
    |
    ----------
*/


void dfs(char** g, int m, int n, int m_max, int n_max){
    /* boundary check */
    #if(1)
    if(m<0 || n<0 || m>=m_max || n>=n_max){
        //printf(" water at: %d, %d\n",m,n);
        return;
    }
        
    #endif

    #if(1)
    /* visit before || water */
    if(  (g[m][n]=='0') ||(g[m][n]=='2')  ){
        return;
    }
        
    //printf("visit %d,%d\n",m,n);
    g[m][n]='2';
    #endif

    #if(1)
    
    //printf("        --> \n");
    dfs(g,m+1,n,m_max,n_max);
    //printf("        <-- \n");
    dfs(g,m-1,n,m_max,n_max);
    //printf("        up \n");
    dfs(g,m,n+1,m_max,n_max);
    //printf("        down \n");
    dfs(g,m,n-1,m_max,n_max);
    #endif
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int island=0;
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j]=='1'){
                //printf(" start to find island at %d,%d\n",i,j);
                dfs(grid,i,j,gridSize,*gridColSize);
                island++;
            }
            
        }
    }        
    return island;
}
