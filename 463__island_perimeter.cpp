class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;

        for(int i=0;i<grid.size();i++){
            if(grid[i][0]) ans++;
                
            for(int j=1;j<grid[0].size();j++){
                if(grid[i][j-1]^grid[i][j]) ans++;
            }

            if(grid[i][grid[0].size()-1]) ans++;
        }

        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]) ans++;

            for(int i=1;i<grid.size();i++){
                if(grid[i-1][j]^grid[i][j]) ans++;
            }

            if(grid[grid.size()-1][j]) ans++;
        }
        
        return ans;
    }
};
