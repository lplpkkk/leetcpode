class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> prefix(n,vector<int>(m));
        long long cur=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j]=(int)cur;
                cur=(cur*grid[i][j])%12345;
            }
        }

        cur=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                prefix[i][j]=(prefix[i][j]*(int)cur)%12345;
                cur=(cur*grid[i][j])%12345;
            }
        }

        return prefix;
    }
};
