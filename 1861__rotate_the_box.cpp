class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();

        //move to the right
        for(int i=0;i<m;i++){
            int empty_pos=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    swap(boxGrid[i][j],boxGrid[i][empty_pos]);
                    empty_pos--;
                }else if(boxGrid[i][j]=='*'){
                    empty_pos=j-1;
                }
            }
        }

        vector<vector<char>> res(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][m-1-i]=boxGrid[i][j];
            }
        }

        return res;
    }
};
