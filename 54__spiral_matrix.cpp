class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x_len=matrix[0].size();
        int y_len=matrix.size();

        int y_min=0;
        int y_max=y_len-1;
        int x_min=0;
        int x_max=x_len-1;
        vector<int> res;

        while(x_min<=x_max&&y_min<=y_max){
            for(int i=x_min;i<=x_max;i++){
                res.push_back(matrix[y_min][i]);
            }
            y_min++;
            for(int i=y_min;i<=y_max;i++){
                res.push_back(matrix[i][x_max]);
            }
            x_max--;
            
            if(y_min<=y_max){
                for(int i=x_max;i>=x_min;i--){
                    res.push_back(matrix[y_max][i]);
                }
                y_max--;
            }
            

            if(x_min<=x_max){
                for(int i=y_max;i>=y_min;i--){
                    res.push_back(matrix[i][x_min]);
                }
                x_min++;
            }
        }
        return res;
    }
};
