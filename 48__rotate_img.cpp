class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();

        //upside down
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        return;
    }
};
