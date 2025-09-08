/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ans=malloc(sizeof(int*)*numRows);

    int* init=malloc(sizeof(int));
    *init=1;

    ans[0]=init;
    for(int i=1;i<numRows;i++){
        int* row=malloc(sizeof(int)*(i+1));
        
        row[0]=row[i]=1;
        for(int j=1;j<i;j++){
            row[j]=ans[i-1][j-1]+ans[i-1][j];
        }

        ans[i]=row;    
    }

    *returnSize=numRows;
    *returnColumnSizes=malloc(sizeof(int)*numRows);
    for(int i=0;i<numRows;i++){
        (*returnColumnSizes)[i]=i+1;
    }
    return ans;
}
