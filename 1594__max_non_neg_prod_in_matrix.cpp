class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long MOD=1e9+7;

        vector<vector<long long>> max_p(m,vector<long long>(n));
        vector<vector<long long>> min_p(m,vector<long long>(n));

        max_p[0][0]=min_p[0][0]=grid[0][0];

        for(int i=1;i<m;i++){
            max_p[i][0]=min_p[i][0]=max_p[i-1][0]*grid[i][0];
        }
        for(int i=1;i<n;i++){
            max_p[0][i]=min_p[0][i]=max_p[0][i-1]*grid[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]>=0){
                    max_p[i][j]=max(max_p[i-1][j],max_p[i][j-1])*grid[i][j];
                    min_p[i][j]=min(min_p[i-1][j],min_p[i][j-1])*grid[i][j];
                }else{
                    max_p[i][j]=min(min_p[i-1][j],min_p[i][j-1])*grid[i][j];
                    min_p[i][j]=max(max_p[i-1][j],max_p[i][j-1])*grid[i][j];
                }
            }
        }

        long long res=max_p[m-1][n-1];
        return (res<0)?-1:res%MOD;
    }
};
