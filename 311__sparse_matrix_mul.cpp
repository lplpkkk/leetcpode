class Solution {
public: 
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        //m*k # k*n 
        int m=mat1.size();
        int k_size=mat1[0].size();
        int n=mat2[0].size();
        vector<vector<int>> ans( m, vector<int>(n));

        for(int i=0;i<m;i++){
            for(int k=0;j<k_size;k++){
                if(mat1[i][k]!=0){
                    for(int j=0;j<n;j++){
                        ans[i][j]+=mat1[i][k]*mat2[k][j];
                    }
                }
            }
        }
        return ans;
    }
}
