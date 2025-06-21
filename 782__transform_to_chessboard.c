

static int bitcnt(int x){
	int n=0;
	while(x){
		n+=(x&1);
		x>>=1;
	}
	return n;
}


static int calcMoves(int mask, int cnt, int n){
	int ones = bitcnt(mask);
	int all = (1<<n)-1;

	if(n&1){
		if((abs(n-2*ones)!=1) ||(abs (n-2*cnt))!=1){
			return -1;
		}

		if(ones==n/2){
			return (n/2-bitcnt(mask&0xaaaaaaaa));
		}else{
			return (n+1)/2-bitcnt(mask&0x55555555);
		}

	}else{
		if(ones!=n/2 || cnt!=n/2){
			return -1;
		}
		int t0=n/2-bitcnt(mask&0xaaaaaaaa);
		int t1=n/2-bitcnt(mask&0x55555555);
		return (t0<t1)?t0:t1;
	}

}

// my explain:
int movesToChessboard(int** board, int boardSize, int* boardColSize) {
    

    //prepare: 
        // mask, rev_mask
            // how row
	int n=boardSize;
	int row_mask=0, col_mask=0;
	for(int i=0;i<n;i++){
		row_mask|=board[0][i]<<i;
		col_mask|=board[i][0]<<i;
	}
	int rev_row=row_mask^((1<<n)-1);
	int rev_col=col_mask^((1<<n)-1);

    //calc steps
        //check if this case possible?
	int cnt_row=0, cnt_col=0;
	for(int i=0;i<n;i++){
		int curR=0, curC=0;
		for(int j=0;j<n;j++){
			curR|=board[i][j]<<j;
			curC|=board[j][i]<<j;
		}
		if(curR!=row_mask && curR!=rev_row){
			return -1;
		}
		if(curC!=col_mask && curC!=rev_col){
			return -1;
		}
		if(curR==row_mask){
			cnt_row++;
		}
		if(curC==col_mask){
			cnt_col++;
		}
	}

	int r=calcMoves(row_mask,cnt_row,n);
	int c=calcMoves(col_mask,cnt_col,n);
	return (r<0 ||c<0)?-1:(r+c);
    
}
