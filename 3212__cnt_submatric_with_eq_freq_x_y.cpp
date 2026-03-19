class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>> prefix(m+1,vector<int>(n+1,0));
        vector<vector<int>> prefiy(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){   
                prefix[i+1][j+1]=prefix[i+1][j]+prefix[i][j+1]-prefix[i][j]+(grid[i][j]=='X');
                prefiy[i+1][j+1]=prefiy[i+1][j]+prefiy[i][j+1]-prefiy[i][j]+(grid[i][j]=='Y');

                if (prefix[i+1][j+1] == prefiy[i+1][j+1] && prefix[i+1][j+1] > 0) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
