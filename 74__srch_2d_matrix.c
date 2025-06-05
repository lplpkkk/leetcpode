
void parse(int *row,int *col, int idx, int row_sz, int col_sz){
    *row=(idx)/col_sz;
    *col=idx%col_sz;
    return;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int total=matrixSize*(matrixColSize[0]);
    int l=0;
    int r=total-1;//11
    int mid;
    int row_idx;
    int col_idx;

    while(l<=r){
        mid=(l+r)/2;
        parse(&row_idx,&col_idx,mid,matrixSize,matrixColSize[0]);
        if(matrix[row_idx][col_idx]==target){
            return true;
        }else if(target<matrix[row_idx][col_idx]){
            r= mid-1;
        }else{
            l= mid+1;
        } 
    }

    return false;

}
