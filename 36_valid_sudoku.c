short r[9]={0,0,0,0,0,0,0,0,0};
short c[9]={0,0,0,0,0,0,0,0,0};
short s[9]={0,0,0,0,0,0,0,0,0};

char find_sub_matrix(char i, char j){
   // printf("%d,%d -->%d \n", i,j, (i/3)*3 +j/3 );
    return (i/3)*3 +j/3;
}

#define BIT(b) (1<<b) 

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    char s_idx;

    memset(r,0,18);
    memset(c,0,18);
    memset(s,0,18);
    
    for(int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            char cur_data = board[i][j]-'0';
            printf("---- checking %d,%d\n",i,j);
            if(cur_data<0){
                continue;
            }

            printf("---- default val 0x%x, 0x%x\n",r[i],c[j]);

            // check row
            printf("r[%d]=0x%x\n",i,r[i]);
            if (r[i] & BIT(cur_data))
                return 0;
            // check column
            printf("c[%d]=0x%x\n",j,c[j]);
            if (c[j] & BIT(cur_data))
                return 0;
            // check sub matrix
            s_idx = find_sub_matrix (i,j);
            printf("s[%d]=0x%x\n",s_idx,s[s_idx]);

            if( s[s_idx] & BIT(cur_data))
                return 0;

            if(board[i][j]!='.'){
                /* update travel log*/
                r[i]|=BIT(cur_data);
                c[j]|=BIT(cur_data);
                s[s_idx]|=BIT(cur_data);
            }    
        }
    } 

    return 1;
}
