void dfs(char** board, int i, int j, int max_i, int max_j){
    if(i<0 || i>=max_i || j<0 || j>=max_j || board[i][j]!='O'){
        return;
    }

    board[i][j]='R'; //mark it as ㄙㄧㄦreachable

    dfs(board, i,j+1,max_i,max_j);
    dfs(board, i,j-1,max_i,max_j);
    dfs(board, i-1,j,max_i,max_j);
    dfs(board, i+1,j,max_i,max_j);

}

void solve(char** board, int boardSize, int* boardColSize) {
    int max_i=boardSize;
    if(max_i<=0){
        return;
    }    

    int max_j=boardColSize[0];

    /* mark boundary */
    for(int i=0;i<max_i;i++){
        dfs(board,i,0,max_i,max_j);       
        dfs(board,i,max_j-1,max_i,max_j);
    }

    for(int j=0;j<max_j;j++){
        dfs(board,0,j,max_i,max_j);       
        dfs(board,max_i-1,j,max_i,max_j);
    }

    for(int i=0;i<max_i;i++){
        for(int j=0;j<max_j;j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }else if(board[i][j]=='R'){
                board[i][j]='O';
            }
        }
    }
}
