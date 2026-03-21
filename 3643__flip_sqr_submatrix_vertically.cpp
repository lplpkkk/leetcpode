class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int mid=x+(k/2);

        for(int i=0;i<(k/2);i++){
            for(int j=0;j<k;j++){
                int row_top=x+i;
                int row_bottom=x+(k-1)-i;

                int tmp=grid[row_top][y+j];
                grid[row_top][y+j]=grid[row_bottom][y+j];
                grid[row_bottom][y+j]=tmp;
            }
        }

        return grid;
    }
};
