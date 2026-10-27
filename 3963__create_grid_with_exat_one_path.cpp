class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m,string(n,'.'));

        for(int i=1;i<m;i++){
            for(int j=0;j<n-1;j++){
                ans[i][j]='#';
            }
        }
        
        return ans;
    }
};
