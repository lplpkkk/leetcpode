int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    int buf[10000][10] = {0}; // 最多 10000 排，記每排的 10 座位
    int real_row[10000];      // 對應 row 的實際排號
    int row_cnt = 0;

     for (int i = 0; i < reservedSeatsSize; i++) {
        int r = reservedSeats[i][0] - 1; // 0-based
        int c = reservedSeats[i][1] - 1; // 0-based

        int j;
        for (j = 0; j < row_cnt; j++) {
            if (real_row[j] == r) break;
        }
        if (j == row_cnt) {
            real_row[row_cnt++] = r;
        }
        buf[j][c] = 1;
    }
    
    int fail=0;

    int ans=0;

    #if(0)
    for(int i=0;i<n;i++){
        //case 1:
        for(int j=2-1;j<=5-1;j++){
            if(buf[i][j]==1){
                fail=1; 
                break;
            }
        }
        if(!fail){
            ans++;
            for(int j=6-1;j<=9-1;j++){
                if(buf[i][j]==1){
                    fail=1; 
                    break;
                }
            }    
            if(!fail) ans++;
        }else{
            fail=0;
            //case2
            for(int j=4-1;j<=7-1;j++){
                if(buf[i][j]==1){
                    fail=1; 
                    break;
                }
            }    
            if(!fail){
                ans++;
            }else{
                for(int j=6-1;j<=9-1;j++){
                    if(buf[i][j]==1){
                        fail=1;
                        break;
                    }
                }
                if(!fail) ans++;
            }
        }
    }
    #endif
    for (int i = 0; i < row_cnt; i++) {
        int* row=buf[i];
        bool left=1, mid=1, right=1;

        for(int j=1;j<=4;j++) if(row[j]) left=0;
        for(int j=3;j<=6;j++) if(row[j]) mid=0;
        for(int j=5;j<=8;j++) if(row[j]) right=0;

        if(left&&right){
            ans+=2;
        }else if(left||mid||right){
            ans+=1;
        }
    }
    ans+=(n-row_cnt)<<1;

    return ans;
}
