class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<long long> row_sum(m,0);
        vector<long long> col_sum(n,0);
        long long total=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
                row_sum[i]+=grid[i][j];
                col_sum[j]+=grid[i][j];
            }
        }
    
        if(total&1){
            return false;
        }

        long long target=total>>1;

        long long current_prefix=0;
        for(int i=0;i<m-1;i++){
            current_prefix+=row_sum[i];
            if(current_prefix==target){
                return true;
            }
        }

        current_prefix=0;
        for(int j=0;j<n-1;j++){
            current_prefix+=col_sum[j];
            if(current_prefix==target){
                return true;
            }
        }

        return false;
    }
};
