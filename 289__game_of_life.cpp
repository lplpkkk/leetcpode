class Solution {
public:
    int m_lim;
    int n_lim;

    bool inside(int m,int n){
        if(m<0||m>=m_lim) return false;
        if(n<0||n>=n_lim) return false;
        return true;
    }

    int all_dir_sum(vector<vector<int>>& b,int m,int n){
        pair<int,int> dir[8]={ {-1,-1},{-1,0},{-1,1},{0,1},
                        {1,1},{1,0},{1,-1},{0,-1}};
        int sum=0;
        for(int i=0;i<8;i++){
            if( inside(m+dir[i].first,n+dir[i].second)){
                sum+=b[m+dir[i].first][n+dir[i].second];
            }
        }
        return sum;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> b=board;
        m_lim=board.size();
        n_lim=board[0].size();

        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                int this_sum=all_dir_sum(board,i,j);
                
                if(board[i][j]==1){
                    if(this_sum>=2&&this_sum<=3){
                        //alive
                        b[i][j]=1;
                    }else{
                        b[i][j]=0;
                    }
                }else{
                    if(this_sum==3){
                        b[i][j]=1;
                    }else{
                        b[i][j]=0;
                    }
                }
                
            }
        }

        board=b;

        return;
    }
};
